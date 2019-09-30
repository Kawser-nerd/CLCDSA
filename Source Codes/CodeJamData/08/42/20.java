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
			int m = in.nextInt();
			int a = in.nextInt();
			out.print( "Case #" + test + ": " );
			boolean ok = false;
			for ( int x2 = 1; x2 <= n; x2 ++ ) {
				int y2 = ( a + x2 - 1 ) / x2;
				if ( y2 > m ) {
					continue;
				}
				int t = x2 * y2 - a;
				if ( t <= n ) {
					out.println( "0 0 " + x2 + " 1 " + t + " " + y2 );
					ok = true;
					break;
				}
				if ( t <= m ) {
					out.println( "0 0 " + x2 + " " + t + " 1 " + y2 );
					ok = true;
					break;
				}
			}
			if ( !ok ) {
				out.println( "IMPOSSIBLE" );
			}
			// ok = false;
			// int x1 = 0;
			// int y1 = 0;
			// LOOP : /*
			// * for ( int x1 = 0; x1 <= n; x1 ++ ) { for ( int y1 = 0; y1 <= m; y1 ++ ) {
			// */
			// for ( int x2 = x1; x2 <= n; x2 ++ ) {
			// for ( int y2 = -m; y2 <= m; y2 ++ ) {
			// for ( int x3 = x2; x3 <= n; x3 ++ ) {
			// for ( int y3 = -m; y3 <= m; y3 ++ ) {
			// int min = Math.min( y1, Math.min( y2, y3 ) );
			// if ( Math.max( y1, Math.max( y2, y3 ) ) - min > m ) {
			// continue;
			// }
			// // int b = x1 * y2 - x2 * y1 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1;
			// int b = x2 * y3 - x3 * y2;
			// if ( a == Math.abs( b ) ) {
			// out.println( " " + x1 + " " + ( y1 - min ) + " " + x2 + " "
			// + ( y2 - min ) + " " + x3 + " " + ( y3 - min ) );
			// ok = true;
			// break LOOP;
			// }
			// }
			// }
			// }
			// }
			//
			// // }
			// // }
			// if ( !ok ) {
			// out.println( " IMPOSSIBLE" );
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
