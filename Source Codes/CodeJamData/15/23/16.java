import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Created by Chushuhuch on 12.04.14.
 */
public class C {

    private static final int MAXH = 10;

    static void solve() {
        int tn = in.nextInt();
        for ( int test = 1; test <= tn; test ++ ) {
            int hn = 0;
            long[] start = new long[MAXH];
            long[] min = new long[MAXH];
            long[] t = new long[MAXH];
            int n = in.nextInt();
            for ( int i = 0; i < n; i ++ ) {
                int d = in.nextInt();
                int h = in.nextInt();
                int m = in.nextInt();
                for ( int j = 0; j < h; j ++ ) {
                    start[hn] = d;
                    min[hn] = m + j;
                    t[hn] = min[hn] * ( 360 - start[hn] );
                    hn ++;
                }
            }
            long r = hn;
            for ( int i = 0; i < hn; i ++ ) {
                long rr = hn;
                for ( int j = 0; j < hn; j ++ ) {
                    if ( t[j] <= t[i] ) {
                        rr --;
                        rr += ( t[i] - t[j] ) / ( 360 * min[j] );
//                        if ( rr > Long.MAX_VALUE / 2 ) {
//                            rr = Long.MAX_VALUE / 2;
//                        }
                    }
                }
                r = Math.min( r, rr );
            }
            out.println( "Case #" + test + ": " + r );
        }
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
