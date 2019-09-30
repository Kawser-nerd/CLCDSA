import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.Vector;

public class C implements Runnable {

	public void solve() throws IOException {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] u = new int[m];
            int[] v = new int[m];
            for ( int i = 0; i < m; i ++ ) {
                u[i] = in.nextInt();
            }
            for ( int i = 0; i < m; i ++ ) {
                v[i] = in.nextInt();
            }
            for ( int i = 0; i < m; i ++ ) {
                for ( int j = 0; j < i; j ++ ) {
                    if ( ( u[j] > u[i] ) || ( ( u[j] == u[i] ) && ( v[j] < v[i] ) ) ) {
                        int t = u[i];
                        u[i] = u[j];
                        u[j] = t;
                        t = v[i];
                        v[i] = v[j];
                        v[j] = t;
                    }
                }
            }
            int[][] en = new int[n + 1][n + 1];
            for ( int i = 0; i <= n; i ++ ) {
                Arrays.fill( en[i], -1 );
            }
            for ( int i = 0; i < m; i ++ ) {
                en[u[i]][v[i]] = i;
            }
            TreeSet< Integer >[] areas = new TreeSet[n];
            int an = 1;
            areas[0] = new TreeSet<Integer>();
            for ( int i = 0; i < n; i ++ ) {
                areas[0].add( i + 1 );
            }
            for ( int i = 0; i < m; i ++ ) {
                int a = 0;
                for ( int j = 0; j < an; j ++ ) {
                    if ( areas[j].contains( u[i] ) && areas[j].contains( v[i] ) ) {
                        a = j;
                        break;
                    }
                }
                TreeSet < Integer > s = new TreeSet<Integer>();
                s.add( u[i] );
                s.add( v[i] );
                for ( int x : areas[a] ) {
                    if ( x > u[i] && x < v[i] ) {
                        s.add( x );
                    }
                }
                areas[a].removeAll( s );
                areas[a].add( u[i] );
                areas[a].add( v[i] );
                areas[an ++] = s;
            }
            Vector< Integer >[] e = new Vector[an];
            for ( int i = 0; i < an; i ++ ) {
                e[i] = new Vector<Integer>();
            }
            int[] toLine = new int[m];
            Arrays.fill( toLine, -1 );
            for ( int i = 0; i < an; i ++ ) {
                for ( int x : areas[i] ) {
                    for ( int y : areas[i] ) {
                        if ( en[x][y] >= 0 ) {
                            if ( toLine[en[x][y]] >= 0 ) {
                                e[i].add( toLine[en[x][y]] );
                                e[toLine[en[x][y]]].add( i );
                            } else {
                                toLine[en[x][y]] = i;
                            }
                        }
                    }
                }
            }
//            for ( int j = 0; j < an; j ++ ) {
//                for ( int x : areas[j] ) {
//                    out.print( x + " " );
//                }
//                out.println();
//            }
//            out.println();
//            for ( int j = 0; j < an; j ++ ) {
//                for ( int x : e[j] ) {
//                    out.print( x + " " );
//                }
//                out.println();
//            }
//            out.println();
            int min = n;
            for ( int i = 0; i < an; i ++ ) {
                min = Math.min( min, areas[i].size() );
            }
            int[] c = new int[n + 1];
            boolean[] g = new boolean[an];
            go( 0, e, areas, c, min, g );

			out.println( "Case #" + test + ": " + min );
            for ( int i = 1; i < n; i ++ ) {
                out.print( c[i] + " " );
            }
            out.println( c[n] );
		}
	}

    private void go( int a, Vector<Integer>[] e, TreeSet<Integer>[] areas, int[] c, int cn, boolean[] g ) {
        if ( g[a] ) {
            return;
        }
        g[a] = true;
        Integer[] area = areas[a].toArray( new Integer[areas[a].size() + 1] );
        area[area.length - 1] = area[0];
        TreeSet < Integer > was = new TreeSet<Integer>();
        for ( Integer v : area ) {
            if ( c[v] > 0 ) {
                was.add( c[v] );
            }
        }
        int cc = 0;
        for ( int i = 0; i < area.length - 1; i ++ ) {
            if ( c[area[i]] <= 0 ) {
                int prev = cc;
                do {
                    cc ++;
                    if ( cc > cn ) {
                        was.clear();
                        cc = 1;
                    }
                } while ( was.contains( cc ) || cc == prev || cc == c[area[i + 1]]);
                c[area[i]] = cc;
            }
        }
        for ( int b : e[a] ) {
            go( b, e, areas, c, cn, g );
        }
    }

    public Scanner in;

	public PrintWriter out;

	C() throws IOException {
		in = new Scanner( System.in );
		// in = new StreamTokenizer( new InputStreamReader( System.in ) );
		out = new PrintWriter( System.out );
	}

	void close() throws IOException {
		out.close();
	}

	void check( boolean f, String msg ) {
		if ( ! f ) {
			out.close();
			throw new RuntimeException( msg );
		}
	}

	public void run() {
		try {
			solve();
			close();
		} catch ( Exception e ) {
            e.printStackTrace( out );
            out.flush();
            throw new RuntimeException( e );
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread( new C() ).start();
	}
}
