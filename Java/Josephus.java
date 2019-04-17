/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * File name  :  Josephus.java
 * Purpose    :  Returns the person who will live in any Josephus problem
 * @author    :  Serena Zafiris
 * Date       :  2017-10-30
 * Description:  Find who lives
 * Notes      :  None
 * Warnings   :  None
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Revision History
 * ================
 *   Ver      Date     Modified by:    Reason for change or modification
 *  -----  ----------  --------------  -------------------------------------------------------------------------
 *  1.0.0  2017-10-30  Serena Zafiris  Initial writing and drafting
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
import java.util.Iterator;
public class Josephus {

  /** Main Method
   * @param args the skip factor and the number of people
   * @return the person who lives
   */

  public static void main ( String[] args ) {
    int skip, peopleNumber;
    /* Checks for user error */
    if( args.length < 2 ){
      throw new IllegalArgumentException( "Please enter a skip factor and a number" );
    }
    try {
      skip = Integer.parseInt( args[0] );
      peopleNumber = Integer.parseInt( args[1] );
    } catch( NumberFormatException nfe ) {
      throw new IllegalArgumentException( "Please enter a number" );
    }
    if( skip < 1 || peopleNumber < 1 ) {
      throw new IllegalArgumentException( "Please enter a number of 1 or greater" );
    }
    /* Calls and builds the CircularList */
    CircularList cl = new CircularList();
    for ( int i = 0; i < peopleNumber; i++ ) {
      cl.add( i );
    }

    Iterator it = cl.iterator();
    int winner = 0;

    /* Loops through the circular list and removes items to find the winner */
    while( it.hasNext() ) {
      for( int i = 1; i < skip; i++ ) {
        it.next();
      }
      it.remove();
    }
    winner = (int) it.next();
    System.out.println( winner );
  }
}
