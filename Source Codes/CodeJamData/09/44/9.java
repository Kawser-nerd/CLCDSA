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

	public void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int n = in.nextInt();
			double[] x = new double[n];
			double[] y = new double[n];
			double[] r = new double[n];
			for ( int i = 0; i < n; i ++ ) {
				x[i] = in.nextDouble();
				y[i] = in.nextDouble();
				r[i] = in.nextDouble();
			}
			double res = 1E100;
			if ( n == 1 ) {
				res = r[0];
			} else if ( n == 2 ) {
				res = Math.max( r[0], r[1] );
			} else {
				for ( int i = 0; i < 3; i ++ ) {
					int j = ( i + 1 ) % 3;
					int k = ( i + 2 ) % 3;
					res = Math.min( res, Math.max( r[i], 0.5 * ( Math
							.hypot( x[j] - x[k], y[j] - y[k] )
							+ r[j] + r[k] ) ) );
				}
			}
			out.println( "Case #" + test + ": " + res );
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
