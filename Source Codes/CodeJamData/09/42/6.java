import java.util.*;
import java.io.*;

public class Main implements Runnable {

	public Scanner in;

	public PrintWriter out;

	Main() throws IOException {
		in = new Scanner( new File( "in" ) );
		out = new PrintWriter( new File( "out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	final static int INF = Integer.MAX_VALUE / 2;

	int m;

	int n;

	int f;

	int pack( int i, int j, int mask1, int mask2 ) {
		return ( ( i * n + j ) << ( 2 * n ) ) + ( mask1 << n )
				+ mask2;
	}

	int mask( char[] c ) {
		int res = 0;
		for ( int i = 0; i < c.length; i ++ ) {
			if ( c[i] == '#' ) {
				res += 1 << i;
			}
		}
		return res;
	}

	char[][] t;

	HashMap < Integer, Integer > r;

	boolean empty( int mask, int b ) {
		return ( mask & ( 1 << b ) ) == 0;
	}

	int go( int x, int y, int mask1, int mask2, int fall ) {
		if ( fall > f ) {
			return INF;
		}
		int pack = pack( x, y, mask1, mask2 );
		if ( r.get( pack ) != null ) {
			return r.get( pack );
		}
		if ( empty( mask2, y ) ) {
			return go( x + 1, y, mask2, mask( t[x + 2] ), fall + 1 );
		}
		int res = INF;
		for ( int t = y; t >= 0; t -- ) {
			if ( !empty( mask1, t ) ) {
				break;
			}
			if ( empty( mask2, t ) ) {
				res = Math.min( res, go( x, t, mask1, mask2, 0 ) );
				break;
			}
			if ( t > 0 && empty( mask1, t - 1 )
					&& !empty( mask2, t - 1 ) ) {
				res = Math.min( res, go( x, t, mask1, mask2
						- ( 1 << ( t - 1 ) ), 0 ) + 1 );
			}
			if ( t < n - 1 && empty( mask1, t + 1 )
					&& !empty( mask2, t + 1 ) ) {
				res = Math.min( res, go( x, t, mask1, mask2
						- ( 1 << ( t + 1 ) ), 0 ) + 1 );
			}
		}
		for ( int t = y; t < n; t ++ ) {
			if ( !empty( mask1, t ) ) {
				break;
			}
			if ( empty( mask2, t ) ) {
				res = Math.min( res, go( x, t, mask1, mask2, 0 ) );
				break;
			}
			if ( t > 0 && empty( mask1, t - 1 )
					&& !empty( mask2, t - 1 ) ) {
				res = Math.min( res, go( x, t, mask1, mask2
						- ( 1 << ( t - 1 ) ), 0 ) + 1 );
			}
			if ( t < n - 1 && empty( mask1, t + 1 )
					&& !empty( mask2, t + 1 ) ) {
				res = Math.min( res, go( x, t, mask1, mask2
						- ( 1 << ( t + 1 ) ), 0 ) + 1 );
			}
		}
		r.put( pack, res );
		return res;
	}

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			m = in.nextInt();
			n = in.nextInt();
			f = in.nextInt();
			t = new char[m + 1][n];
			for ( int i = 0; i < m; i ++ ) {
				t[i] = in.next().toCharArray();
			}
			Arrays.fill( t[m], '#' );
			r = new HashMap < Integer, Integer >();
			for ( int j = 0; j < n; j ++ ) {
				for ( int mask = 0; mask < ( 1 << n ); mask ++ ) {
					r.put( pack( m - 1, j, mask, mask( t[m] ) ), 0 );
				}
			}
			int res = go( 0, 0, mask( t[0] ), mask( t[1] ), 0 );
			if ( res >= INF / 2 ) {
				out.println( "Case #" + test + ": No" );
			} else {
				out.println( "Case #" + test + ": Yes " + res );
			}
			out.flush();
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
