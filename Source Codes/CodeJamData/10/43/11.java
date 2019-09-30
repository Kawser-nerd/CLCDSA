//package c;

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
            int s = 128;
            boolean[][] b = new boolean[s][s];
            int r = in.nextInt();
            boolean alive = false;
            for ( int i = 0; i < r; i ++ ) {
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int x2 = in.nextInt();
                int y2 = in.nextInt();
                for ( int x = x1; x <= x2; x ++ ) {
                    for ( int y = y1; y <= y2; y ++ ) {
                        b[x][y] = true;
                        alive = true;
                    }
                }
            }
            int t = 0;
            while ( alive ) {
                t ++;
                alive = false;
                boolean[][] b1 = new boolean[s][s];
                for ( int x = 1; x < b.length; x ++ ) {
                    for ( int y = 1; y < b[x].length; y ++ ) {
                        if ( b[x - 1][y] ) {
                            if ( b[x][y - 1] || b[x][y] ) {
                                b1[x][y] = true;
                            }
                        } else if ( b[x][y - 1] && b[x][y] ) {
                            b1[x][y] = true;
                        }
                        if ( b1[x][y] ) {
                            alive = true;
                            if ( ( x == b1.length - 1 ) || ( y == b1.length - 1 ) ) {
                                s *= 2;
                            }
                        }
                    }
                }
                b = b1;
            }
			out.println( "Case #" + test + ": " + t );
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
