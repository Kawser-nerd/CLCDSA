import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B implements Runnable {

	public void solve() throws IOException {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int m = in.nextInt();
            int n = in.nextInt();
            in.nextLine();
            int[][] w = new int[m][n];
            for ( int i = 0; i < m; i ++ ) {
                char[] c = in.nextLine().toCharArray();
                for ( int j = 0; j < n; j ++ ) {
                    w[i][j] = c[j] - '0';
                }
            }
            int[][] ls = new int[n][m + 1];
            int[][] wlsx = new int[n][m + 1];
            int[][] wlsy = new int[n][m + 1];
            for ( int i = 0; i < n; i ++ ) {
                for ( int j = 0; j < m; j ++ ) {
                    ls[i][j + 1] = ls[i][j] + w[j][i];
                    wlsx[i][j + 1] = wlsx[i][j] + w[j][i] * j;
                    wlsy[i][j + 1] = wlsy[i][j] + w[j][i] * i;
                }
            }
            int res = -1;
            for ( int k = Math.min( m, n ); k >= 3; k -- ) {
                boolean ok = false;
                for ( int x = 0; x + k <= m; x ++ ) {
                    long s = 0;
                    long wsx = 0;
                    long wsy = 0;
                    for ( int y = 0; y < k; y ++ ) {
                        s += ls[y][x + k] - ls[y][x];
                        wsx += wlsx[y][x + k] - wlsx[y][x];
                        wsy += wlsy[y][x + k] - wlsy[y][x];
                    }
                    if ( check( w, x, 0, k, s, wsx, wsy ) ) {
                        ok = true;
                        break;
                    }
                    for ( int y = 0; y + k < n; y ++ ) {
                        s += ls[y + k][x + k] - ls[y + k][x] - ( ls[y][x + k] - ls[y][x] );
                        wsx += wlsx[y + k][x + k] - wlsx[y + k][x] - ( wlsx[y][x + k] - wlsx[y][x] );
                        wsy += wlsy[y + k][x + k] - wlsy[y + k][x] - ( wlsy[y][x + k] - wlsy[y][x] );
                        if ( check( w, x, y + 1, k, s, wsx, wsy ) ) {
                            ok = true;
                            break;
                        }
                    }
                    if ( ok ) {
                        break;
                    }
                }
                if ( ok ) {
                    res = k;
                    break;
                }
            }
			out.println( "Case #" + test + ": " + ( ( res == -1 ) ? "IMPOSSIBLE" : res ) );
		}
	}

    private boolean check( int[][] w, int x, int y, int k, long s, long wsx, long wsy ) {
        s -= w[x][y] + w[x][y + k - 1] + w[x + k - 1][y] + w[x + k - 1][y + k - 1];
        wsx -= ( w[x][y] + w[x][y + k - 1] ) * x + ( w[x + k - 1][y] + w[x + k - 1][y + k - 1] ) * ( x + k - 1 );
        wsy -= ( w[x][y] + w[x + k - 1][y] ) * y + ( w[x][y + k - 1] + w[x + k - 1][y + k - 1] ) * ( y + k - 1 );
        return ( s * ( 2 * x + k - 1 ) == 2 * wsx ) && ( s * ( 2 * y + k - 1 ) == 2 * wsy );
    }

    public Scanner in;

	public PrintWriter out;

	B() throws IOException {
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
		new Thread( new B() ).start();
	}
}
