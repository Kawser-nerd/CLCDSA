import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A implements Runnable {

	public void solve() throws IOException {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int n = in.nextInt();
            char[][] c = new char[n][n];
            for ( int i = 0; i < n; i ++ ) {
                c[i] = in.next().toCharArray();
            }
            int[] w = new int[n];
            int[] l = new int[n];
            double[] wp = new double[n];
            for ( int i = 0; i < n; i ++ ) {
                for ( int j = 0; j < n; j ++ ) {
                    if ( c[i][j] == '1' ) {
                        w[i] ++;
                    } else if ( c[i][j] == '0' ) {
                        l[i] ++;
                    }
                }
                wp[i] = w[i] * 1.0 / ( w[i] + l[i] );
            }
            double[] owp = new double[n];
            for ( int i = 0; i < n; i ++ ) {
                for ( int j = 0; j < n; j ++ ) {
                    if ( c[i][j] != '.' ) {
                        owp[i] += ( w[j] - ( c[j][i] - '0' ) ) * 1.0 / ( w[j] + l[j] - 1 );
                    }
                }
                owp[i] /= w[i] + l[i];
            }
            double[] oowp = new double[n];
            for ( int i = 0; i < n; i ++ ) {
                for ( int j = 0; j < n; j ++ ) {
                    if ( c[i][j] != '.' ) {
                        oowp[i] += owp[j];
                    }
                }
                oowp[i] /= w[i] + l[i];
            }

			out.println( "Case #" + test + ":" );
            for ( int i = 0; i < n; i ++ ) {
                out.println( 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i] );
            }
		}
	}

	public Scanner in;

	public PrintWriter out;

	A() throws IOException {
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
		new Thread( new A() ).start();
	}
}
