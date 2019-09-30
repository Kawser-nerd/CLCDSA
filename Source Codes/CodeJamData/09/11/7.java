import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	boolean happy( int x, int b, boolean[] gone, boolean[] happy ) {
		// System.out.println( b + " " + x );
		if ( x < gone.length && gone[x] ) {
			return happy[x];
		}
		if ( x < gone.length ) {
			gone[x] = true;
		}
		int y = 0;
		int xc = x;
		// System.out.print( x );
		while ( x > 0 ) {
			int t = x / b;
			int r = x - t * b;
			y += r * r;
			x = t;
		}
		// System.out.println( " -> " + y );
		boolean h = happy( y, b, gone, happy );
		if ( xc < gone.length ) {
			happy[xc] = h;
		}
		return h;
	}

	void run() {
		int tn = in.nextInt();
		in.nextLine();
		boolean[][] gone = new boolean[11][1000];
		boolean[][] happy = new boolean[11][1000];
		for ( int i = 0; i < 11; i ++ ) {
			gone[i][1] = true;
			happy[i][1] = true;
		}
		for ( int test = 1; test <= tn; test ++ ) {
			String[] s = in.nextLine().split( " " );
			int n = s.length;
			int[] b = new int[n];
			for ( int i = 0; i < n; i ++ ) {
				b[i] = new Integer( s[i] );
			}
			for ( int i = 2;; i ++ ) {
				boolean ok = true;
				for ( int j = 0; j < n; j ++ ) {
					ok &= happy( i, b[j], gone[b[j]], happy[b[j]] );
					// System.out.println( "  " + b[j] + " " + i + " "
					// + happy( i, b[j], gone[j], happy[j] ) );
				}
				if ( ok ) {
					out.println( "Case #" + test + ": " + i );
					out.flush();
					break;
				}
				if ( ( i & ( ( 1 << 20 ) - 1 ) ) == 0 ) {
					System.out.println( i );
				}
			}
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
