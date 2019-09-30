import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "";

	public StreamTokenizer in;

	public PrintWriter out;

	void open() throws IOException {
		in = new StreamTokenizer( new BufferedReader( new FileReader( new File( FNAME + ".in" ) ) ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	int nextInt() throws IOException {
		in.nextToken();
		return ( int ) in.nval;
	}

	int h;

	int w;

	char cur;

	char get( int x, int y, int[][] a, char[][] r ) {
		if ( r[x][y] >= 'a' ) {
			return r[x][y];
		}
		int bx = -1;
		int by = -1;
		int ba = 10000000;
		for ( int i = -1; i <= 1; i ++ ) {
			for ( int j = -1; j <= 1; j ++ ) {
				if ( Math.abs( i ) + Math.abs( j ) != 1 ) {
					continue;
				}
				if ( x + i >= 0 && x + i < h && y + j >= 0 && y + j < w ) {
					if ( a[x + i][y + j] < a[x][y] && a[x + i][y + j] < ba ) {
						ba = a[x + i][y + j];
						bx = x + i;
						by = y + j;
					}
				}
			}
		}
		if ( bx == -1 ) {
			r[x][y] = cur ++;
		} else {
			r[x][y] = get( bx, by, a, r );
		}
		return r[x][y];
	}

	void run() throws IOException {
		int tn = nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			h = nextInt();
			w = nextInt();
			int[][] a = new int[h][w];
			for ( int i = 0; i < h; i ++ ) {
				for ( int j = 0; j < w; j ++ ) {
					a[i][j] = nextInt();
				}
			}
			char[][] r = new char[h][w];
			cur = 'a';
			for ( int i = 0; i < h; i ++ ) {
				for ( int j = 0; j < w; j ++ ) {
					r[i][j] = get( i, j, a, r );
				}
			}
			out.println( "Case #" + test + ":" );
			for ( int i = 0; i < h; i ++ ) {
				for ( int j = 0; j < w; j ++ ) {
					out.print( r[i][j] + " " );
				}
				out.println();
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
