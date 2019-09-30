//package c;

import java.util.*;
import java.io.*;

public class Main implements Runnable {

	public Scanner in;

	public PrintWriter out;
    private static final int MAXN = 500;
    private static final long M = 100003;

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
    
    long add( long a, long b ) {
        long r = a + b;
        if ( r >= M ) {
            r -= M;
        }
        return r;
    }

    long mul( long a, long b ) {
        return ( a * b ) % M;
    }

	public void run() {
        long[][] c= new long[MAXN + 1][MAXN + 1];
        for ( int i = 0; i <= MAXN; i ++ ) {
            c[i][0] = 1;
            for ( int j = 1; j <= i; j ++ ) {
                c[i][j] = add( c[i - 1][j - 1], c[i - 1][j] );
            }
        }
        long[][] s = new long[MAXN + 1][MAXN];
        for ( int i = 2; i <= MAXN; i ++ ) {
            s[i][1] = 1;
            for ( int j = 2; j < i; j ++ ) {
                for ( int k = 1; k < j; k ++ ) {
                    s[i][j] = add( s[i][j], mul( s[j][j - k], c[i - j - 1][k - 1] ) );
                }
            }
        }
        long[] r = new long[MAXN + 1];
        for ( int i = 2; i <= MAXN; i ++ ) {
            for ( int j = 1; j < i; j ++ ) {
                r[i] = add( r[i], s[i][j] );
            }
        }
        int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            int n = in.nextInt();
			out.println( "Case #" + test + ": " + r[n] );
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
