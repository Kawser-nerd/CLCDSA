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

	final static char[] t = "welcome to code jam".toCharArray();

	void run() throws IOException {
		int tn = new Integer( in.readLine() );
		for ( int test = 1; test <= tn; test ++ ) {
			char[] c = in.readLine().toCharArray();
			int[][] r = new int[t.length + 1][c.length + 1];
			Arrays.fill( r[0], 1 );
			for ( int i = 0; i < t.length; i ++ ) {
				for ( int j = 0; j < c.length; j ++ ) {
					r[i + 1][j + 1] = r[i + 1][j];
					if ( t[i] == c[j] ) {
						r[i + 1][j + 1] += r[i][j];
						r[i + 1][j + 1] %= 10000;
					}
				}
			}
			String a = r[t.length][c.length] + "";
			while ( a.length() < 4 ) {
				a = "0" + a;
			}
			out.println( "Case #" + test + ": " + a );
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
