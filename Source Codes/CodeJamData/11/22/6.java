import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B implements Runnable {

	public void solve() throws IOException {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int n = in.nextInt();
            int d = in.nextInt();
            int[] v = new int[n];
            int[] x = new int[n];
            for ( int i = 0; i < n; i ++ ) {
                x[i] = in.nextInt();
                v[i] = in.nextInt();
            }
            double l = 0.0;
            double r = 1E14;
            while ( r - l > 0.1 ) {
                double t = 0.5 * ( l + r );
                double X = Double.NEGATIVE_INFINITY;
                boolean ok = true;
                for ( int i = 0; i < n; i ++ ) {
                    X = Math.max( X + d, x[i] - t ) + ( v[i] - 1 ) * 1.0 * d;
                    if ( Math.abs( X - x[i] ) > t ) {
                        ok = false;
                        break;
                    }
                }
                if ( ok ) {
                    r = t;
                } else {
                    l = t;
                }
            }
			out.println( "Case #" + test + ": " + Math.round( l + r ) * 0.5 );
		}
	}

	public Scanner in;

	public PrintWriter out;

	B() throws IOException {
		in = new Scanner( System.in );
		// in = new StreamTokenizer( new InputStreamReader( System.in ) );
		out = new PrintWriter( System.out );
	}

	void close() throws IOException {
		out.close();
	}

	void check( boolean f, String msg ) {
		if ( ! f ) {
			out.close();
			throw new RuntimeException( msg );
		}
	}

	public void run() {
		try {
			solve();
			close();
		} catch ( Exception e ) {
            e.printStackTrace( out );
            out.flush();
            throw new RuntimeException( e );
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread( new B() ).start();
	}
}
