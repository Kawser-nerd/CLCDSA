import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "d";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	int k;

	int[] p;

	boolean[] u;

	char[] c;

	int go( int cur ) {
		if ( cur >= k ) {
			int n = c.length;
			int gn = n / k;
			char[] d = new char[n];
			for ( int i = 0; i < gn; i ++ ) {
				for ( int j = 0; j < k; j ++ ) {
					d[i * k + j] = c[i * k + p[j]];
				}
			}
			int r = 1;
			for ( int i = 1; i < n; i ++ ) {
				if ( d[i] != d[i - 1] ) {
					r ++;
				}
			}
			return r;
		} else {
			int r = Integer.MAX_VALUE / 2;
			for ( int i = 0; i < k; i ++ ) {
				if ( !u[i] ) {
					p[cur] = i;
					u[i] = true;
					r = Math.min( r, go( cur + 1 ) );
					u[i] = false;
				}
			}
			return r;
		}
	}

	void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			k = in.nextInt();
			c = in.next().toCharArray();
			p = new int[k];
			u = new boolean[k];
			out.println( "Case #" + test + ": " + go( 0 ) );
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
