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
		int tn = new Integer( in.nextLine() );
		for ( int test = 1; test <= tn; test ++ ) {
			int sEN = new Integer( in.nextLine() );
			String[] sE = new String[sEN];
			for ( int i = 0; i < sEN; i ++ ) {
				sE[i] = in.nextLine();
			}
			int qN = new Integer( in.nextLine() );
			int[][] r = new int[qN + 1][sEN];
			for ( int i = 0; i < qN; i ++ ) {
				Arrays.fill( r[i + 1], Integer.MAX_VALUE / 2 );
				String s = in.nextLine();
				for ( int j = 0; j < sEN; j ++ ) {
					for ( int k = 0; k < sEN; k ++ ) {
						if ( j != k ) {
							r[i + 1][k] = Math.min( r[i + 1][k], r[i][j] + 1 );
						}
					}
					if ( !s.equals( sE[j] ) ) {
						r[i + 1][j] = Math.min( r[i + 1][j], r[i][j] );
					}
				}
			}
			int res = Integer.MAX_VALUE;
			for ( int i = 0; i < sEN; i ++ ) {
				res = Math.min( res, r[qN][i] );
			}
			out.println( "Case #" + test + ": " + res );
		}
	}

	public static void main( String[] args ) throws IOException {
		Main solution = new Main();
		solution.open();
		solution.run();
		solution.close();
	}
}
