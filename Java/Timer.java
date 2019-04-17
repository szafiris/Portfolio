/**
 *  File name     :  Timer.java
 *  Purpose       :  Provides the methods for the field class
 *  Author        :  Serena Zafiris
 *  Date          :  2017-03-28
 *  Description   :
 *  Notes         :
 *  Warnings      :  None
 *  Exceptions    :  None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Revision History
 *  ----------------
 *            Rev      Date     Modified by:    Reason for change/modification
 *           -----  ----------  ------------    -----------------------------------------------------------
 *  @version 1.0.0  2017-03-23  Serena Zafiris  Initial writing
 *  @version 1.0.1  2017-03-28  Serena Zafiris  Added tick and toString and tester
 *  @version 1.0.1  2017-04-02  Serena Zafiris  Edited tester
 */

public class Timer {
  /* Variables go here */
  private double hours;
  private double mins;
  private double secs;
  private double totalSecs;

  public Timer() {
    hours = 0;
    mins = 0;
    secs = 0;
    totalSecs = 0;
  }

  public double tick() {
    totalSecs = totalSecs + 1;
    secs = totalSecs;
    if( secs >= 60 ) {
      mins = secs / 60 ;
      secs = secs % 60;
    }
    if( mins >= 60 ) {
      hours =  mins / 60;
      mins = mins % 60;
    }
    return totalSecs;
  }

  public String toString() {
    return Math.floor( hours ) + ":" + Math.floor( mins ) + ":" + secs ;
  }

  public static void main( String args[] ) {
    /* Tick tested fully in Clock.java */
    Timer t = new Timer();
    System.out.println( t.toString() );
    t.tick();
    System.out.println( t.toString() );
  }
}
