/** Binary Tree */

import java.util.Iterator;
import java.util.Collection;
import java.util.Stack;
import java.util.Arrays;

public class BinaryTree implements java.util.Collection {

  public Node rootNode;

  /* node builder
  * Constructs and builds all the nodes in the class BinaryTree
  */
  public class Node {
    public Object info;
    private Node llink;
    private Node rlink;

    public Node() {
      llink = null;
      rlink = null;
      info = null;
    }

    public Node( Object s, Node left, Node right ) {
      this.info = s;
      this.llink = left;
      this.rlink = right;
    }

    /* setLeftLink() */
    public void setLeftLink( Node ptr ) {
      this.llink = ptr;
    }

    /* setRightLink() */
    public void setRightLink( Node ptr ) {
      this.rlink = ptr;
    }

    /* setInfo() */
    public void setInfo( String s ) {
      this.info = s;
    }

    /* getInfo()
     * @returns info object from node
     */
    public Object getInfo() {
      return this.info;
    }

    /* getLeftLink()
     * @returns node's left link
     */
    public Node getLeftLink() {
      return this.llink;
    }

    /* getRightLink()
     * @returns node's right link
     */
    public Node getRightLink() {
      return this.rlink;
    }
  }

  /* Constructors
   * Builds Binary Tree
   */
  public BinaryTree() {
    rootNode = null;
  }

  public BinaryTree( Object obj ) {
    rootNode = new Node( obj, null, null );
  }

  /* Add Method
   * This adds a new root decorated with obj.
   * The original tree becomes the left subtree of the new root.
   */
  public boolean add( Object obj ) {
    Node t = new Node( obj, rootNode, null );
    rootNode = t;
    return true;
  }

  /* addAll Method
   * This adds all members of Collection c to this binary tree
   */
  public boolean addAll( java.util.Collection c ) {
    for( Object o : c ) {
      Node t = new Node( o, rootNode, null );
      rootNode = t;
    }
    return true;
  }

  /*clear method */
  public void clear() {
    this.rootNode = null;
  }

  /* Construct Method */
  public static BinaryTree construct( Object obj, BinaryTree leftSubtree, BinaryTree rightSubtree ) {
    BinaryTree bt = new BinaryTree();
    bt.add( obj );
    if( leftSubtree != null ) {
      bt.rootNode.setLeftLink( leftSubtree.rootNode );
    }
    if( rightSubtree != null ) {
      bt.rootNode.setRightLink( rightSubtree.rootNode );
    }
    return bt;
  }

  /* Contains Method
   * Returns true iff this binary tree contains (at least) one example of Object obj.
   */
  public boolean contains( Object obj ) {
    Object o = obj;
    boolean contains = false;
    Iterator it = this.iterator();
    while( it.hasNext() ) {
      if( it.next() == o ) {
        contains = true;
      }
    }
    return contains;
  }

  /* ContainsAll Method
   * Returns true iff this binary tree contains at least one example of each DIFFERENT object in Collection c, i.e.,
   * although c may contain several examples of some (same) object,
   * this binary tree is only required to contain one such example.
   */
  public boolean containsAll( java.util.Collection c ) {
    int count = 0;
    for( Object o : c ) {
      if( this.contains( o ) ) {
        count++;
      }
    }
    return count == c.size();
  }

  /* equals Method
   * Returns true iff this binary tree contains the same structure and objects as binary tree b.
   */
  public boolean equals( Object obj ) {
    BinaryTree b = (BinaryTree)obj;
    Iterator it = this.iterator();
    Iterator bt = b.iterator();
    int count = 0;
    if( this.size() == b.size() ) {
      while( it.hasNext() ) {
        if( this.rootNode.getInfo() == b.rootNode.getInfo() ) {
          count++;
        }
        it.next();
        bt.next();
      }
      return count == this.size();
    } else {
      return false;
    }
  }

  /* hashCode method
   * Returns the hashcode for this binary tree.
   */
  public int hashCode() {
    return super.hashCode();
  }

  /* inorder iterator
   * NOT SUPPORTED FOR THIS CLASS
   */
  public java.util.Iterator inorderIterator() {
    throw new UnsupportedOperationException();
  }

  /* isEmpty Method
   * Returns true iff this binary tree is empty.
   */
  public boolean isEmpty() {
    if( rootNode == null ) {
      return true;
    } else {
      return false;
    }
  }

  /* preorder iterator
   * Returns a preorder iterator for this binary tree.
   * All bets are off if the tree changes during the traversal.
   */
  public java.util.Iterator iterator() {
      return new SpecialIterator( this );
  }

  public class SpecialIterator implements Iterator {
    private BinaryTree tree;
    private Node next;
    private Stack stack = new Stack<Node>();
    private boolean hasNext = false;

    public SpecialIterator ( BinaryTree t ) {
      this.tree = t;
      this.next = rootNode;
    }

    /** hasNext Method */
    public boolean hasNext() {
      return !hasNext;
    }

    /** next Method
     * Starts at root node, returns info then goes to next node
     */
    public Object next() {
      Object obj = next.getInfo();
      if( next.getLeftLink() != null ) {
        if( next.getRightLink() != null ) {
          stack.push( next.getRightLink() );
        }
        next = next.getLeftLink();
      } else if( next.getRightLink() != null ) {
        next = next.getRightLink();
      } else if( !stack.empty() ) {
        next = (Node)stack.pop();
      } else {
        hasNext = true;
      }
      return obj;
    }

    /** remove Method
     * NOT SUPPORTED FOR THIS CLASS
     */
    public void remove() {
      throw new UnsupportedOperationException();
    }
  }

  /** remove Method
   * NOT SUPPORTED FOR THIS CLASS
   */
  public boolean remove( Object obj ) {
    throw new UnsupportedOperationException();
  }

  /* removeAll Method
   * NOT SUPPORTED FOR THIS CLASS
   */
  public boolean removeAll( java.util.Collection c ) {
    throw new UnsupportedOperationException();
  }

  /* retainAll Method
   * NOT SUPPORTED FOR THIS CLASS
   */
  public boolean retainAll( java.util.Collection c ) {
    throw new UnsupportedOperationException();
  }

  /* size method
   * Returns true iff this binary tree contains the same structure and objects as binary tree b.
   */
  public int size() {
    return sizeHelper( rootNode );
  }

  /* sizeHelper method
   * Helps to calculate size of BinaryTree
   */
  private int sizeHelper( Node n ) {
    if( n == null) {
      return 0;
    } else {
      return( sizeHelper( n.llink ) + 1 + sizeHelper( n.rlink ) );
    }
  }

  /* to array method
   * Returns an array with a reference to each object in this tree.
   */
  public Object[] toArray() {
    Object[] o = new Object[this.size()];
    int i = 0;
    Iterator it = this.iterator();
    while( it.hasNext() ) {
      o[i] = it.next();
      i++;
    }
    return o;
  }

  /* to array method
   * NOT SUPPORTED
   */
  public Object[] toArray( Object[] obj ) {
    throw new UnsupportedOperationException();
  }

  /* toString Method
   * Returns a string representation of this binary tree using ()
   */
  public String toString() {
    return toString(new StringBuilder(), this.rootNode).toString();
  }

  /* StringBuilder Method
   * Helps to build string of BinaryTree
   */
  private static StringBuilder toString(StringBuilder s, Node n) {
    s.append('(');
    if (n != null) {
      s.append(n.getInfo());
      toString(s.append(" "), n.getLeftLink());
      toString(s.append(" "), n.getRightLink());
    }
    return s.append(')');
  }

  public static void main( String[] args ) {
    /**
    *Some BinaryTrees.
    */
    BinaryTree bt0 = BinaryTree.construct ( "B1", null, null );
    BinaryTree bt1 = BinaryTree.construct ( "B2", null, null );
    BinaryTree bt2 = BinaryTree.construct ( "B", bt0, bt1 );
    BinaryTree bt3 = BinaryTree.construct ( "C", null, null );
    BinaryTree bt = BinaryTree.construct ( "A", bt2, bt3 );
    BinaryTree t = BinaryTree.construct( "A", null, null );
    BinaryTree t1 = BinaryTree.construct( "A", t, null );

    /**
    *size() method tester.
    */
    System.out.println( "\n    size() METHOD:\n" +
    "    ==================================" );
    System.out.println( "Size (should be 5): " + bt.size());

    /**
    *contains() method tester.
    */
    System.out.println( "\n    contains() METHOD:\n" +
    "    ==================================" );
    System.out.println( "\n" + bt.toString() );
    System.out.println( "testing contains A: " + bt.contains( "A" ) );
    System.out.println( "testing contains Z: " + bt.contains( "Z" ) );

    /**
    *add() method tester.
    */
    System.out.println( "\n    add() METHOD:\n" +
    "    ==================================" );
    bt.add( 616 );
    System.out.println( "\n" + bt.toString() );
    Collection<String> c = new java.util.ArrayList<String>();
    c.add( "Y" );
    c.add( "3" );
    bt.add( c );
    System.out.println( "\n" + bt.toString() );

    /**
    *containsAll() method tester.
    */
    System.out.println( "\n    containsAll() METHOD:\n" +
    "    ==================================" );
    System.out.println( "testing contains A, A: " + bt.containsAll( t1 ) );
    System.out.println( "testing contains Y, 3: " + bt.containsAll( c ) );

    /**
    *iterator method tester.
    */
    Iterator it = bt.iterator();
    System.out.println( "\n    iterator:\n" +
    "    ==================================" );
    System.out.println( it.hasNext() );
    System.out.println( it.next() );
    System.out.println(it.hasNext());
    System.out.println( it.next() );
    System.out.println(it.hasNext());
    System.out.println( it.next() );
    System.out.println(it.hasNext());
    System.out.println( it.next() );
    System.out.println(it.hasNext());
    System.out.println( it.next() );
    System.out.println(it.hasNext());
    System.out.println( it.next() );
    System.out.println( it.hasNext() );
    System.out.println( it.next() );
    System.out.println( it.hasNext() );

    /**
    *isEmpty() and clear() method tester.
    */
    System.out.println( "\n    isEmpty() and clear() METHODS:\n" +
    "    ==================================" );
    bt.clear();
    System.out.println( bt.isEmpty() );
    System.out.println( t1.isEmpty() );
    System.out.println( "Size: " + bt.size() );

    /**
    *addAll() method tester.
    */
    System.out.println( "\n    addAll() METHOD:\n" +
    "    ==================================" );
    bt.addAll( c );
    System.out.println( "\n" + bt.toString() );
    BinaryTree e = new BinaryTree();
    e.addAll( c );
    System.out.println( "\n" + e.toString() );

    /**
    *equals() method tester.
    */
    System.out.println( "\n    equals() METHOD:\n" +
    "    ==================================" );
    System.out.println( "\n" + bt.equals( e ) );
    System.out.println( "\n" + t1.equals( bt ) );

    /**
    *constructors.
    */
    System.out.println( "\n    constructors:\n" +
    "    ==================================" );
    BinaryTree j = new BinaryTree();
    BinaryTree d = new BinaryTree( 115 );
    System.out.println( j.toString() );
    System.out.println( d.toString() );

    /*List of toString() method and construct() test.
    */
    System.out.println( "    TESTING construct() AND toString() METHOD:\n" +
    "    ==================================" );
    System.out.println( "\n" + bt.toString() );
    System.out.println( "\n" + d.toString() );

    /**
    *toArray() method tester.
    */
    System.out.println( "\n   toArray() METHODS:\n" +
    "    ==================================" );
    System.out.println( Arrays.toString( bt.toArray() ) );
    System.out.println( Arrays.toString( t1.toArray() ) );

    /**
    *hashCode() method tester.
    */
    System.out.println( "\n    hashCode() METHODS:\n" +
    "    ==================================" );
    System.out.println( "hashCode: " + bt.hashCode() );
    System.out.println( "hashCode: " + t1.hashCode() );
  }
}
