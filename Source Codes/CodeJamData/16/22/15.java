import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created by Chushuhuch on 12.04.14.
 */
public class B {

    private static void solve() {
        int tn = in.nextInt();
        for ( int test = 1; test <= tn; test ++ ) {
            char[] c = in.next().toCharArray();
            char[] j = in.next().toCharArray();
            long[] best = findBest( c, j, 0, 0 );
            out.println( "Case #" + test + ": " + String.format( "%0" + c.length + "d", best[0] ) + " " + String.format( "%0" + c.length + "d", best[1] ) );
        }
    }

    private static long[] findBest( char[] c, char[] j, int p, long curCJ ) {
        if ( p >= c.length ) {
            return new long[] { curCJ, curCJ };
        }
        if ( c[p] != '?' && j[p] != '?' ) {
            if ( c[p] == j[p] ) {
                return findBest( c, j, p + 1, curCJ * 10 + c[p] - '0' );
            } else {
                return findClosest( c, j, p + 1, curCJ * 10 + c[p] - '0', curCJ * 10 + j[p] - '0' );
            }
        }
        if ( c[p] == '?' ) {
            if ( j[p] == '?' ) {
                long[] best = findBest( c, j, p + 1, curCJ * 10 );
                best = max( best, findClosest( c, j, p + 1, curCJ * 10, curCJ * 10 + 1 ) );
                best = max( best, findClosest( c, j, p + 1, curCJ * 10 + 1, curCJ * 10 ) );
                return best;
            }
            long[] best = findBest( c, j, p + 1, curCJ * 10 + j[p] - '0' );
            if ( j[p] > '0' ) {
                best = max( best, findClosest( c, j, p + 1, curCJ * 10 + j[p] - 1 - '0', curCJ * 10 + j[p] - '0' ) );
            }
            if ( j[p] < '9' ) {
                best = max( best, findClosest( c, j, p + 1, curCJ * 10 + j[p] + 1 - '0', curCJ * 10 + j[p] - '0' ) );
            }
            return best;
        } else {
            long[] best = findBest( c, j, p + 1, curCJ * 10 + c[p] - '0' );
            if ( c[p] > '0' ) {
                best = max( best, findClosest( c, j, p + 1, curCJ * 10 + c[p] - '0', curCJ * 10 + c[p] - 1 - '0' ) );
            }
            if ( c[p] < '9' ) {
                best = max( best, findClosest( c, j, p + 1, curCJ * 10 + c[p] - '0', curCJ * 10 + c[p] + 1 - '0' ) );
            }
            return best;
        }
    }

    private static long[] max( long[] cj1, long[] cj2 ) {
        if ( Math.abs( cj1[0] - cj1[1] ) < Math.abs( cj2[0] - cj2[1] ) ||
                ( Math.abs( cj1[0] - cj1[1] ) == Math.abs( cj2[0] - cj2[1] ) && ( cj1[0] < cj2[0] ||
                                                                                ( cj1[0] == cj2[0] && cj1[1] < cj2[1] ) ) ) ) {
            return cj1;
        } else {
            return cj2;
        }
    }

    private static long[] findClosest( char[] c, char[] j, int p, long curC, long curJ ) {
        for ( ; p < c.length; p ++ ) {
            long newC = curC * 10 + ( c[p] == '?' ? ( curC < curJ ? 9 : 0 ) : c[p] - '0' );
            long newJ = curJ * 10 + ( j[p] == '?' ? ( curJ < curC ? 9 : 0 ) : j[p] - '0' );
            curC = newC;
            curJ = newJ;
        }
        return new long[] { curC, curJ };
    }

    private static Scanner in;
    private static PrintWriter out;

    public static void main( String[] args ) {
        Locale.setDefault(Locale.US);
        in = new Scanner( System.in );
        out = new PrintWriter( System.out );
        solve();
        out.close();
    }
}
