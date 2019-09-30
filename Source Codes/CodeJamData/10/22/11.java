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
            int n = in.nextInt();
            int k = in.nextInt();
            long b = in.nextLong();
            int t = in.nextInt();
            long[] x = new long[n];
            long[] v = new long[n];
            for ( int i = 0; i < n; i ++ ) {
                x[i] = in.nextLong();
            }
            for ( int i = 0; i < n; i ++ ) {
                v[i] = in.nextLong();
            }
            int cur = n - 1;
            int r = 0;
            for ( int i = 0; i < k; i ++ ) {
                while ( cur >= 0 && x[cur] + t * v[cur] < b ) {
                    cur --;
                    r += ( k - i );
                }
                //out.println( cur );
                cur --;
            }
            out.println( "Case #" + test + ": " + ( ( cur < -1 ) ? "IMPOSSIBLE" : r ) );
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
