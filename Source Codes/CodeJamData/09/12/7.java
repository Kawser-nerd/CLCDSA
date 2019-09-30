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

	void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int r = in.nextInt();
			int c = in.nextInt();
			int[][] nsg = new int[r][c];
			int[][] ewg = new int[r][c];
			int[][] off = new int[r][c];
			for ( int i = r - 1; i >= 0; i -- ) {
				for ( int j = 0; j < c; j ++ ) {
					nsg[i][j] = in.nextInt();
					ewg[i][j] = in.nextInt();
					off[i][j] = in.nextInt();
				}
			}
			boolean[][] g = new boolean[2 * r][2 * c];
			long[][] dist = new long[2 * r][2 * c];
			for ( int i = 0; i < 2 * r; i ++ ) {
				Arrays.fill( dist[i], Long.MAX_VALUE / 2 );
			}
			dist[0][0] = 0;
			while ( !g[2 * r - 1][2 * c - 1] ) {
				int bi = -1;
				int bj = -1;
				long bd = Long.MAX_VALUE / 4;
				for ( int i = 0; i < 2 * r; i ++ ) {
					for ( int j = 0; j < 2 * c; j ++ ) {
						if ( !g[i][j] && dist[i][j] <= bd ) {
							bd = dist[i][j];
							bi = i;
							bj = j;
						}
					}
				}
				// out.println( bi + " " + bj );
				g[bi][bj] = true;
				long m = nsg[bi >> 1][bj >> 1] + ewg[bi >> 1][bj >> 1];
				long t = ( ( -bd + off[bi >> 1][bj >> 1] ) % m + m ) % m;
				if ( t > ewg[bi >> 1][bj >> 1] ) {
					t = 0;
				}
				if ( bi > 0 ) {
					if ( ( bi & 1 ) == 0 ) {
						dist[bi - 1][bj] = Math.min( dist[bi - 1][bj], bd + 2 );
					} else {
						dist[bi - 1][bj] = Math.min( dist[bi - 1][bj], bd + 1 + t );
					}
				}
				if ( bi < 2 * r - 1 ) {
					if ( ( bi & 1 ) == 1 ) {
						dist[bi + 1][bj] = Math.min( dist[bi + 1][bj], bd + 2 );
					} else {
						dist[bi + 1][bj] = Math.min( dist[bi + 1][bj], bd + 1 + t );
					}
				}
				t = ( ( -bd + off[bi >> 1][bj >> 1] + nsg[bi >> 1][bj >> 1] ) % m + m ) % m;
				if ( t > nsg[bi >> 1][bj >> 1] ) {
					t = 0;
				}
				if ( bj > 0 ) {
					if ( ( bj & 1 ) == 0 ) {
						dist[bi][bj - 1] = Math.min( dist[bi][bj - 1], bd + 2 );
					} else {
						dist[bi][bj - 1] = Math.min( dist[bi][bj - 1], bd + 1 + t );
					}
				}
				if ( bj < 2 * c - 1 ) {
					if ( ( bj & 1 ) == 1 ) {
						dist[bi][bj + 1] = Math.min( dist[bi][bj + 1], bd + 2 );
					} else {
						dist[bi][bj + 1] = Math.min( dist[bi][bj + 1], bd + 1 + t );
					}
				}
				// for ( int i = 0; i < 2 * r; i ++ ) {
				// for ( int j = 0; j < 2 * c; j ++ ) {
				// out.print( dist[i][j] + " " );
				// }
				// out.println();
				// }
				// out.println();
			}
			out.println( "Case #" + test + ": " + dist[2 * r - 1][2 * c - 1] );
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
