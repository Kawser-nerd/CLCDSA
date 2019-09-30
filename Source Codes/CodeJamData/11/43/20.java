import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C implements Runnable {

	public void solve() throws IOException {
        boolean[] np = new boolean[1000001];
        int[] p = new int[np.length];
        int pn = 0;
        for ( int i = 2; i < np.length; i ++ ) {
            if ( np[i] ) {
                continue;
            }
            p[pn ++] = i;
            for ( int j = 2 * i; j < np.length; j += i ) {
                np[j] = true;
            }
        }
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            long n = in.nextLong();
            long r = ( n > 1 ) ? 1 : 0;
            for ( int i = 0; ( i < pn ) && ( p[i] * ( ( long ) p[i] ) <= n ); i ++ ) {
                long m = n;
                do {
                    r ++;
                    m /= p[i];
                } while ( m >= p[i] );
                r --;
            }
			out.println( "Case #" + test + ": " + r );
		}
	}

	public Scanner in;

	public PrintWriter out;

	C() throws IOException {
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
		new Thread( new C() ).start();
	}
}
