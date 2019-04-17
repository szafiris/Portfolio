/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * File name  :  CircularList.java
 * Purpose    :  Making my own iterator class
 * @author    :  Serena Zafiris
 * Date       :  2017-10-30
 * Description:  This program implements the iterator class
 * Notes      :  None
 * Warnings   :  None
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Revision History
 * ================
 *   Ver      Date     Modified by:    Reason for change or modification
 *  -----  ----------  --------------  -------------------------------------------------------------------
 *  1.0.0  2017-10-30  Serena Zafiris  Initial writing and drafting
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
import java.util.Iterator;
public class CircularList implements Iterable {
  private Node firstNode;
  private Node lastNode;

  /* Node class: builds the nodes */
  private class Node {
    int a;
    public Node next;
    public Node( int b ) {
      a = b;
      next = null;
    }
  }

  /** add method
   * @param index the position the node is in the CircularList
   * adds nodes to the end of the CircularList
   */
  public void add( int index ) {
    if( size() == 0 ) {
      Node nextNode = new Node ( index );
      firstNode = nextNode;
      lastNode = nextNode;
    } else {
      Node nextNode = new Node( index );
      lastNode.next = nextNode;
      nextNode.next = firstNode;
      lastNode = nextNode;
    }
  }

  /** size method
  * @return the size of the CircularList
  */
  public int size() {
    int count = 1;
    if( firstNode == null ) {
      return 0;
    }
    if( firstNode.next == null ) {
      return 1;
    }
    Node current = firstNode;
    while( current.next != firstNode ) {
      count++;
      current = current.next;
    }
    return count;
  }

  /** get method
  * @return the posotion of the node in the list (i.e. the variable labeled index)
  */
  public int get( Node node ) {
    return node.a;
  }

  public Iterator iterator(){
    return new SpecialIterator( this );
  }

  private class SpecialIterator implements Iterator {
    private Node nextIndex;
    private CircularList cl;

    public SpecialIterator ( CircularList l ) {
        this.cl = l;
        this.nextIndex = cl.firstNode;
    }

    /** hasNext Method
    * @return a boolean stating whether there is a next item in the CircularList
    */
    public boolean hasNext() {
      if( cl.size() > 1 ) {
        return true;
      } else {
        return false;
      }
    }
    /** next Method
    * @return the current item in the current place in the CircularList
    * moves to the next item in the CircularList
    */
    public Object next() {
      Object obj = cl.get( nextIndex );
      nextIndex = nextIndex.next;
      return obj;
    }
    /** remove Method
    * removes the current item in the CircularList
    */
    public void remove() {
      if( cl.size() > 1 ) {
        Node temp = nextIndex;
        for( int i = 0; i < cl.size() - 1; i++ ) {
          temp = temp.next;
        }

        if(nextIndex == firstNode){
          firstNode = firstNode.next;
        }

        if(nextIndex == lastNode) {
          lastNode = temp;
        }
        temp.next = nextIndex.next;
        nextIndex = nextIndex.next;
      }
    }
  }
}
