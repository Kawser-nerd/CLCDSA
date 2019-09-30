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

	void check( boolean f, String msg ) {
		if ( !f ) {
			out.close();
			throw new RuntimeException( msg );
		}
	}

	public class State implements Comparable < State > {

		int[] x;

		int[] y;

		State( int[] X, int[] Y ) {
			x = X;
			y = Y;
			sort();
		}

		State( char[][] c, char our ) {
			int n = 0;
			for ( int i = 0; i < c.length; i ++ ) {
				for ( char t : c[i] ) {
					if ( t == our || t == 'w' ) {
						n ++;
					}
				}
			}
			x = new int[n];
			y = new int[n];
			int cur = 0;
			for ( int i = 0; i < c.length; i ++ ) {
				for ( int j = 0; j < c[i].length; j ++ ) {
					if ( c[i][j] == our || c[i][j] == 'w' ) {
						x[cur] = i;
						y[cur ++] = j;
					}
				}
			}
			sort();
		}

		void sort() {
			for ( int i = 0; i < x.length; i ++ ) {
				for ( int j = 0; j < i; j ++ ) {
					if ( x[i] < x[j]
							|| ( x[i] == x[j] && y[i] < y[j] ) ) {
						int t = x[i];
						x[i] = x[j];
						x[j] = t;
						t = y[i];
						y[i] = y[j];
						y[j] = t;
					}
				}
			}
		}

		public int compareTo( State s ) {
			int i = 0;
			while ( i < x.length && x[i] == s.x[i] && y[i] == s.y[i] ) {
				i ++;
			}
			if ( i < x.length ) {
				if ( x[i] != s.x[i] ) {
					return new Integer( x[i] ).compareTo( s.x[i] );
				} else {
					return new Integer( y[i] ).compareTo( s.y[i] );
				}
			} else {
				return 0;
			}
		}

		public boolean equals( State s ) {
			return compareTo( s ) == 0;
		}

		boolean isDangerous() {
			boolean[] g = new boolean[x.length];
			g[0] = true;
			for ( int i = 0; i < x.length; i ++ ) {
				for ( int j = 0; j < x.length; j ++ ) {
					if ( g[j] ) {
						for ( int k = 0; k < x.length; k ++ ) {
							if ( Math.abs( x[j] - x[k] )
									+ Math.abs( y[j] - y[k] ) <= 1 ) {
								g[k] = true;
							}
						}
					}
				}
			}
			boolean r = true;
			for ( int i = 0; i < x.length; i ++ ) {
				r &= g[i];
			}
			return !r;
		}

		final int[] dx = new int[] { -1, 0, 1, 0 };

		final int[] dy = new int[] { 0, -1, 0, 1 };

		State move( int b, int d, char[][] t ) {
			for ( int i = -1; i <= 1; i += 2 ) {
				if ( x[b] + i * dx[d] < 0
						|| x[b] + i * dx[d] >= t.length
						|| y[b] + i * dy[d] < 0
						|| y[b] + i * dy[d] >= t[0].length ) {
					// out.println( "! " + b + " " + d + " out " + i
					// + " " + dx[d] + " " + dy[d] + " "
					// + ( x[b] + i * dx[d] < 0 ) + " "
					// + ( x[b] + i * dx[d] >= t.length ) + " "
					// + ( y[b] + i * dy[d] < 0 ) + " "
					// + ( y[b] + i * dy[d] >= t[0].length ) );
					return null;
				}
				if ( t[x[b] + i * dx[d]][y[b] + i * dy[d]] == '#' ) {
					return null;
				}
				for ( int j = 0; j < x.length; j ++ ) {
					if ( j != b && x[j] == x[b] + i * dx[d]
							&& y[j] == y[b] + i * dy[d] ) {
						return null;
					}
				}
			}
			int[] X = x.clone();
			int[] Y = y.clone();
			X[b] += dx[d];
			Y[b] += dy[d];
			return new State( X, Y );
		}

		public String toString() {
			String s = "";
			for ( int i = 0; i < x.length; i ++ ) {
				s += "( " + x[i] + ", " + y[i] + ") ";
			}
			return s;
		}
	}

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int m = in.nextInt();
			int n = in.nextInt();
			char[][] t = new char[m][];
			for ( int i = 0; i < m; i ++ ) {
				t[i] = in.next().toCharArray();
			}
			State start = new State( t, 'o' );
			State end = new State( t, 'x' );
			ArrayList < State > q = new ArrayList < State >();
			int l = 0;
			q.add( start );
			TreeMap < State, Integer > d = new TreeMap < State, Integer >();
			d.put( start, 0 );
			TreeMap < State, State > prev = new TreeMap < State, State >();
			while ( d.get( end ) == null && q.size() > l ) {
				State cur = q.get( l ++ );
				int dist = d.get( cur ) + 1;
				boolean dangerous = cur.isDangerous();
				// out.println( cur + " " + dist + " " + dangerous );
				for ( int i = 0; i < cur.x.length; i ++ ) {
					for ( int dir = 0; dir < 4; dir ++ ) {
						State next = cur.move( i, dir, t );
						if ( next != null
								&& ( !dangerous || !next
										.isDangerous() )
								&& d.get( next ) == null ) {
							d.put( next, dist );
							q.add( next );
							prev.put( next, cur );
							// out.println( "    " + next );
						}
					}
				}
			}
			out.print( "Case #" + test + ": " );
			if ( d.get( end ) == null ) {
				out.println( "-1" );
			} else {
				out.println( d.get( end ) );
				// while ( !end.equals( start ) ) {
				// out.println( " " + end );
				// end = prev.get( end );
				// }
			}
			System.out.println( test );
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
