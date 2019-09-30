import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		Locale.setDefault( Locale.US );
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int c = in.nextInt();
			int n = in.nextInt();
			double[][] C = new double[c + 1][c + 1];
			for ( int i = 0; i <= c; i ++ ) {
				C[i][0] = 1;
				for ( int j = 1; j <= i; j ++ ) {
					C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
				}
			}
			double[] F = new double[c + 1];
			F[0] = 1.0;
			for ( int i = 1; i <= c; i ++ ) {
				F[i] = F[i - 1] * i;
			}
			double[][] p = new double[c + 1][1000];
			p[n][1] = 1.0;
			double r = p[c][1];
			p[c][1] = 0.0;
			for ( int k = 2; k < p[0].length; k ++ ) {
				for ( int a = n; a <= c; a ++ ) {
					for ( int i = 0; i <= n; i ++ ) {
						p[a][k] += p[a - i][k - 1]
								* C[c - ( a - i )][i]
								* C[a - i][n - i] // * C[n][i]
								/ C[c][n];// ( F[c] / F[c - n] );
					}
					// if ( k < 10 ) {
					// out.println( k + " " + a + " " + p[a][k] );
					// }
				}
				r += k * p[c][k];
				p[c][k] = 0;
			}
			for ( int a = 0; a <= c; a ++ ) {
				assert Math.abs( p[a][p[a].length - 1]
						- p[a][p[a].length - 2] ) < 1E-7;
			}
			out.format( "Case #%d: %.7f\n", test, r );
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread() {

			public void run() {
				try {
					Main solution = new Main();
					solution.open();
					solution.run();
					solution.close();
				} catch ( Exception e ) {
					throw new RuntimeException( e );
				}
			}
		}.start();
	}
}
