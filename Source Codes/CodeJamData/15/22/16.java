import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created by Chushuhuch on 12.04.14.
 */
public class B {

    static void solve() {
        int tn = in.nextInt();
        for ( int test = 1; test <= tn; test ++ ) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            if ( n <= ( r * c + 1 ) / 2 ) {
                out.println( "Case #" + test + ": 0" );
                continue;
            }
            out.println( "Case #" + test + ": " + Math.min( count( r, c, n, 0 ), count( r, c, n, 1 ) ) );
        }
    }

    private static int count( int r, int c, int n, int odd ) {
        boolean[][] g = new boolean[r][c];
        for ( int i = 0; i < r; i ++ ) {
            for ( int j = 0; j < c; j++ ) {
                if ( ( i + j ) % 2 == odd ) {
                    g[i][j] = true;
                    n --;
                }
            }
        }
        if ( ! g[0][0] && n > 0 ) {
            g[0][0] = true;
            n --;
        }
        if ( ! g[0][c - 1] && n > 0 ) {
            g[0][c - 1] = true;
            n --;
        }
        if ( ! g[r - 1][0] && n > 0 ) {
            g[r - 1][0] = true;
            n --;
        }
        if ( ! g[r - 1][c - 1] && n > 0 ) {
            g[r - 1][c - 1] = true;
            n --;
        }
        for ( int i = 0; i < r; i ++ ) {
            for ( int j = 0; j < c; j ++ ) {
                if ( ( i == 0 || j == 0 || i == r - 1 || j == c - 1 ) && ! g[i][j] && n > 0 ) {
                    g[i][j] = true;
                    n --;
                }
            }
        }
        for ( int i = 0; i < r; i ++ ) {
            for ( int j = 0; j < c; j ++ ) {
                if ( ! g[i][j] && n > 0 ) {
                    g[i][j] = true;
                    n --;
                }
            }
        }
        int res = 0;
        for ( int i = 0; i < r; i ++ ) {
            for ( int j = 1; j < c; j ++ ) {
                if ( g[i][j] && g[i][j - 1] ) {
                    res ++;
                }
            }
        }
        for ( int i = 1; i < r; i ++ ) {
            for ( int j = 0; j < c; j ++ ) {
                if ( g[i][j] && g[i - 1][j] ) {
                    res ++;
                }
            }
        }
        return res;
    }

    static Scanner in;
    static PrintWriter out;

    public static void main( String[] args ) throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        in = new Scanner( new File( "C:\\programming\\contests\\GCJ\\GCJ_2015\\2015.05.02_Round_1B\\in" ) );
        out = new PrintWriter( new File( "C:\\programming\\contests\\GCJ\\GCJ_2015\\2015.05.02_Round_1B\\out" ) );
        solve();
        out.close();
    }
}
