//package a;

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
            int k = in.nextInt();
            int size = 2 * k - 1;
            int[][] d = new int[size][size];
            in.nextLine();
            for ( int i = 0; i < size; i ++ ) {
                char[] c = in.nextLine().toCharArray();
                for ( int j = 0; j < c.length; j ++ ) {
                    d[i][j] = ( int ) ( c[j] - '0' );
                }
                for ( int j = c.length; j < size; j ++ ) {
                    d[i][j] = ( int ) ( ' ' - '0' );
                }
            }
            int bx = 0;
            int by = 0;
            for ( int c = 0; c < size; c ++ ) {
                boolean sx = true;
                boolean sy = true;
                for ( int i = 0; i < size; i ++ ) {
                    int i1 = 2 * c - i;
                    if ( i1 < 0 || i1 >= size ) {
                        continue;
                    }
                    for ( int j = 0; j < size; j ++ ) {
                        if ( d[i][j] >= 0 && d[i1][j] >= 0 ) {
                            sx &= d[i][j] == d[i1][j];
                        }
                        //out.println( sx + " " + d[i][j] + " " + d[i1][j] );
                        if ( d[j][i] >= 0 && d[j][i1] >= 0 ) {
                            sy &= d[j][i] == d[j][i1];
                        }
                        //out.println( sy + " " + d[j][i] + " " + d[j][i1] + " " + j + " " + i + " " + i1 );
                    }
                }
                if ( sx && Math.abs( k - 1 - c ) < Math.abs( k - 1 - bx ) ) {
                    bx = c;
                }
                if ( sy && Math.abs( k - 1 - c ) < Math.abs( k - 1 - by ) ) {
                    by = c;
                }
                /*out.print( c );
                if ( sx ) {
                    out.print( "x" );
                }
                if ( sy ) {
                    out.print( "y" );
                }
                out.println();*/
            }
            int now = k * k;
            k += Math.abs( k - 1 - bx ) + Math.abs( k - 1 - by );
            int then = k * k;
			out.println( "Case #" + test + ": " + ( then - now ) );
            //out.println( bx + " " + by );
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
