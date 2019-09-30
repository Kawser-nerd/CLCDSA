import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "b";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int n = in.nextInt();
			// n = 2000;
			int m = in.nextInt();
			// m = 2000;
			int[] t = new int[m];
			int[][] x = new int[m][];
			int[][] y = new int[m][];
			// Random rnd = new Random();
			for ( int i = 0; i < m; i ++ ) {
				t[i] = in.nextInt();
				// t[i] = 2000;
				x[i] = new int[t[i]];
				y[i] = new int[t[i]];
				// for ( int j = 0; j < t[i]; j ++ ) {
				// x[i][j] = j;
				// }
				// y[i][rnd.nextInt( t[i] )] = 1;
				for ( int j = 0; j < t[i]; j ++ ) {
					x[i][j] = in.nextInt() - 1;
					y[i][j] = in.nextInt();
				}
			}
			int[] r = new int[n];
			boolean possible = true;
			for ( int i = 0; i < n; i ++ ) {
				for ( int j = 0; j < m; j ++ ) {
					boolean ok = false;
					for ( int k = 0; k < t[j]; k ++ ) {
						if ( r[x[j][k]] == y[j][k] ) {
							ok = true;
							break;
						}
					}
					if ( !ok ) {
						for ( int k = 0; k < t[j]; k ++ ) {
							if ( y[j][k] == 1 ) {
								ok = true;
								r[x[j][k]] = 1;
							}
						}
						if ( !ok ) {
							possible = false;
							break;
						}
					}
				}
			}
			out.print( "Case #" + test + ":" );
			if ( !possible ) {
				out.println( " IMPOSSIBLE" );
			} else {
				for ( int i = 0; i < n; i ++ ) {
					out.print( " " + r[i] );
				}
				out.println();
			}

			// int bm = -1;
			// int bn = n + 1;
			// for ( int u = 0; u < ( 1 << n ); u ++ ) {
			// boolean ok = true;
			// for ( int i = 0; i < m; i ++ ) {
			// ok = false;
			// for ( int j = 0; j < t[i]; j ++ ) {
			// // out.println( u + " " + i + " " + j + " "
			// // + ( ( ( u >> x[i][j] ) & 1 ) == y[i][j] ) + " " + x[i][j] + " "
			// // + y[i][j] );
			// if ( ( ( u >> x[i][j] ) & 1 ) == y[i][j] ) {
			// ok = true;
			// break;
			// }
			// }
			// if ( !ok ) {
			// break;
			// }
			// }
			// if ( ok ) {
			// int tt = 0;
			// int v = u;
			// while ( v > 0 ) {
			// tt += v & 1;
			// v >>= 1;
			// }
			// if ( tt < bn ) {
			// bm = u;
			// bn = tt;
			// }
			// }
			// }
			// out.print( "Case #" + test + ":" );
			// if ( bn > n ) {
			// out.println( " IMPOSSIBLE" );
			// } else {
			// for ( int i = 0; i < n; i ++ ) {
			// out.print( " " + ( ( bm >> i ) & 1 ) );
			// }
			// out.println();
			// }
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
