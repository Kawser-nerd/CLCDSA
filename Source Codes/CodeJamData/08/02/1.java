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
			int t = in.nextInt();
			int[] n = new int[] { in.nextInt(), in.nextInt() };
			int[][] e = new int[2 * ( n[0] + n[1] )][3];
			for ( int i = 0; i < n[0] + n[1]; i ++ ) {
				String[] u = in.next().split( ":" );
				e[2 * i][0] = new Integer( u[0] ) * 60 + new Integer( u[1] );
				u = in.next().split( ":" );
				e[2 * i + 1][0] = new Integer( u[0] ) * 60 + new Integer( u[1] ) + t;
				if ( i < n[0] ) {
					e[2 * i][1] = -1;
					e[2 * i + 1][2] = 1;
				} else {
					e[2 * i][2] = -1;
					e[2 * i + 1][1] = 1;
				}
			}
			for ( int i = 0; i < e.length; i ++ ) {
				for ( int j = i + 1; j < e.length; j ++ ) {
					if ( e[i][0] > e[j][0]
							|| ( e[i][0] == e[j][0] && ( e[i][1] < e[j][1] || ( e[i][1] == e[j][1] && e[i][2] < e[j][2] ) ) ) ) {
						int[] x = e[i];
						e[i] = e[j];
						e[j] = x;
					}
				}
			}
			int[] need = new int[2];
			int[] cur = new int[2];
			for ( int i = 0; i < e.length; i ++ ) {
				// out.println( i + " " + e[i][0] + " " + e[i][1] + " " + e[i][2] );
				for ( int j = 0; j < 2; j ++ ) {
					cur[j] += e[i][j + 1];
					if ( cur[j] < 0 ) {
						need[j] ++;
						cur[j] ++;
					}
				}
				// out.println( cur[0] + " " + cur[1] + " " + need[0] + " " + need[1] );
			}
			out.println( "Case #" + test + ": " + need[0] + " " + need[1] );
		}
	}

	public static void main( String[] args ) throws IOException {
		Main solution = new Main();
		solution.open();
		solution.run();
		solution.close();
	}
}
