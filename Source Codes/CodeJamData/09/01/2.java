import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "";

	public BufferedReader in;

	public PrintWriter out;

	void open() throws IOException {
		in = new BufferedReader( new FileReader( new File( FNAME + ".in" ) ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() throws IOException {
		String[] u = in.readLine().split( " " );
		int l = new Integer( u[0] );
		int d = new Integer( u[1] );
		int n = new Integer( u[2] );
		String[] dict = new String[d];
		for ( int i = 0; i < d; i ++ ) {
			dict[i] = in.readLine();
		}
		for ( int test = 1; test <= n; test ++ ) {
			boolean[][] can = new boolean[l][26];
			String s = in.readLine();
			int p = 0;
			for ( int i = 0; i < l; i ++ ) {
				if ( s.charAt( p ) == '(' ) {
					do {
						p ++;
						if ( s.charAt( p ) == ')' ) {
							break;
						}
						can[i][s.charAt( p ) - 'a'] = true;
					} while ( true );
				} else {
					can[i][s.charAt( p ) - 'a'] = true;
				}
				p ++;
			}
			int r = 0;
			for ( int i = 0; i < d; i ++ ) {
				boolean ok = true;
				for ( int j = 0; j < l; j ++ ) {
					ok &= can[j][dict[i].charAt( j ) - 'a'];
				}
				if ( ok ) {
					r ++;
				}
			}
			out.println( "Case #" + test + ": " + r );
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
