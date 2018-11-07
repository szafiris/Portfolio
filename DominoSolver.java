// Domino Program
// Serena Zafiris

public class DominoSolver {

  // Recursive version of DominoSolver
  static int solve( int d[], int i, int j ) {
    int max = 0;
    for ( int k = i; k < j; k++ ) {
      int count =  solve( d, i, k ) + solve( d, k + 1, j ) + d[i - 1] * d[k] * d[j];
      if ( count > max ) {
        max = count;
      }
    }
    return max;
  }

  // Main Method
  public static void main( String[] args ) {
    int[] dominoVals = new int[args.length - ( ( args.length - 2 ) / 2 )];
    int[] dominos = new int[args.length];
    if( args.length % 2 != 0 ) {
      throw new IllegalArgumentException();
    }
    if( args.length < 4 ) {
      throw new IllegalArgumentException();
    }
    try {
      for( int i = 0; i < args.length; i++ ) {
        dominos[i] = Integer.parseInt( args[i] );
      }
    } catch( NumberFormatException nfe ) {
      throw new IllegalArgumentException();
    }
    for( int i = 1; i < args.length - 1; i+=2 ) {
      if( Integer.parseInt( args[i] ) != Integer.parseInt( args[i + 1] ) ) {
        throw new IllegalArgumentException();
      }
    }
    for( int i = 0; i < args.length; i++ ) {
      if( dominos[i] < 0 ) {
        throw new IllegalArgumentException();
      }
    }
    dominoVals[0] = dominos[0];
    int j = 1;
    for( int i = 1; i < dominos.length - 1; i++ ) {
      if( dominos[i] == dominos[i - 1] ) {
        dominoVals[j] = dominos[i];
        i++;
        j++;
      }
    }
    dominoVals[dominoVals.length - 1] = dominos[dominos.length - 1];
    System.out.println(solve(dominoVals, 1, dominoVals.length - 1));
  }
}
