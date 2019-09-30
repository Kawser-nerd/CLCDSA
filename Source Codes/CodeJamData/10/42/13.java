//package b;

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
		if ( ! f ) {
			out.close();
			throw new RuntimeException( msg );
		}
	}

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int p = in.nextInt();
            int n = 1 << p;
            int[] visit = new int[n];
            for ( int i = 0; i < n; i ++ ) {
                visit[i] = p - in.nextInt();
            }
            int[] cost = new int[n];
            for ( int i = n / 2; i > 0; i /= 2 ) {
                for ( int j = i; j < i * 2; j ++ ) {
                    cost[j] = in.nextInt();
                }
            }
            int[][] r = new int[2 * n][p + 1];
            for ( int i = 0; i < r.length; i ++ ) {
                Arrays.fill( r[i], Integer.MAX_VALUE / 4 );
            }
            for ( int i = n; i < 2 * n; i ++ ) {
                for ( int j = visit[i - n]; j <= p; j ++ ) {
                    r[i][j] = 0;
                }
            }
            for ( int i = n - 1; i > 0; i -- ) {
                for ( int j = 0; j < p; j ++ ) {
                    r[i][j] = Math.min( r[2 * i][j] + r[2 * i + 1][j], cost[i] + r[2 * i][j + 1] + r[2 * i + 1][j + 1] );
                    r[i][j] = Math.min( r[i][j], Integer.MAX_VALUE / 4 );
                }
                r[i][p] = Math.min( r[2 * i][p] + r[2 * i + 1][p], Integer.MAX_VALUE / 4 );
            }
            /*for ( int i = 1; i < r.length; i ++ ) {
                out.print( i + ": " );
                for ( int j = 0; j < r[i].length; j ++ ) {
                    out.print( r[i][j] + " " );
                }
                out.println();
            }*/
            /*int res = r[1][0];
            for ( int i = 1; i <= p; i ++ ) {
                res = Math.min( res, r[1][i] );
            }*/
			out.println( "Case #" + test + ": " + r[1][0] );
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
