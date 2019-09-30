import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "a";

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
			long[] u = new long[n];
			for ( int i = 0; i < n; i ++ ) {
				u[i] = in.nextLong();
			}
			long[] v = new long[n];
			for ( int i = 0; i < n; i ++ ) {
				v[i] = in.nextLong();
			}
			Arrays.sort( u );
			Arrays.sort( v );
			long r = 0;
			for ( int i = 0; i < n; i ++ ) {
				r += u[i] * v[n - 1 - i];
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
