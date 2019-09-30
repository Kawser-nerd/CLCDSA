import java.util.*;
import java.io.*;

public class Main implements Runnable {

	public Scanner in;

	public PrintWriter out;

	Main() throws IOException {
		in = new Scanner( new File( "in" ) );
		out = new PrintWriter( new File( "out" ) );
	}

	void check( boolean f ) {
		if ( !f ) {
			throw new RuntimeException();
		}
	}

	void close() throws IOException {
		out.close();
	}

	boolean[][] e;

	int[] u;

	boolean[] g;

	int n;

	boolean go( int v ) {
		if ( v < 0 ) {
			return true;
		}
		if ( g[v] ) {
			return false;
		}
		g[v] = true;
		for ( int i = 0; i < n; i ++ ) {
			if ( e[v][i] && go( u[i] ) ) {
				u[i] = v;
				return true;
			}
		}
		return false;
	}

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			n = in.nextInt();
			int k = in.nextInt();
			int[][] y = new int[n][k];
			for ( int i = 0; i < n; i ++ ) {
				for ( int j = 0; j < k; j ++ ) {
					y[i][j] = in.nextInt();
				}
			}
			e = new boolean[n][n];
			for ( int i = 0; i < n; i ++ ) {
				for ( int j = 0; j < n; j ++ ) {
					e[i][j] = true;
					for ( int l = 0; l < k; l ++ ) {
						e[i][j] &= y[i][l] < y[j][l];
					}
				}
			}
			// for ( int i = 0; i < n; i ++ ) {
			// for ( int j = 0; j < n; j ++ ) {
			// out.print( e[i][j] + " " );
			// }
			// out.println();
			// }
			// out.println();
			u = new int[n];
			Arrays.fill( u, -1 );
			int r = 0;
			for ( int i = 0; i < n; i ++ ) {
				g = new boolean[n];
				if ( go( i ) ) {
					r ++;
				}
			}
			// for ( int i = 0; i < n; i ++ ) {
			// out.print( u[i] + " " );
			// }
			// out.println();
			check( r < n );
			out.println( "Case #" + test + ": " + ( n - r ) );
		}
		try {
			close();
		} catch ( IOException e ) {
			e.printStackTrace();
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread( new Main() ).start();
	}
}
