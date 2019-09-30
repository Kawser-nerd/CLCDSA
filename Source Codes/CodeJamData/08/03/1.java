import java.util.*;
import java.io.*;

public class Main {

	final static String FNAME = "c";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		Locale.setDefault( Locale.US );
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	double f( double u ) {
		if ( u < 0 || u > 1 ) {
			out.println( "f : " + u );
		}
		return Math.asin( Math.min( u, 1 ) ) + u * Math.sqrt( Math.abs( 1 - u * u ) );
	}

	void run() {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			double f = in.nextDouble();
			double R = in.nextDouble();
			double t = in.nextDouble();
			double r = in.nextDouble();
			double g = in.nextDouble();
			t += f;
			if ( g - 2 * f <= 0 ) {
				out.println( "Case #" + test + ": 1.0" );
				continue;
			}
			int holeN = ( int ) ( ( R - t - r - f ) / ( 2 * r + g ) ) + 1;
			double area = 0.0;
			for ( int i = 0; i < holeN; i ++ ) {
				for ( int j = 0; j < holeN; j ++ ) {
					double x = r + f + i * ( 2 * r + g );
					double y = r + f + j * ( 2 * r + g );
					double dx = g - 2 * f;
					double dy = g - 2 * f;
					// out.println( i + " " + j + " " + x + " " + dx + " " + y + " " + dy );
					if ( x * x + ( y + dy ) * ( y + dy ) < ( R - t ) * ( R - t ) ) {
						double xx = Math.sqrt( Math.abs( ( R - t ) * ( R - t ) - ( y + dy )
								* ( y + dy ) ) );
						if ( xx > x + dx ) {
							xx = x + dx;
						}
						// out.println( x + " -> " + xx );
						area += dy * Math.abs( xx - x );
						dx -= xx - x;
						x = xx;
					} else {
						dy = Math.sqrt( Math.abs( ( R - t ) * ( R - t ) - x * x ) ) - y;
						if ( dy < 0 ) {
							dy = 0;
						}
					}
					if ( y * y + ( x + dx ) * ( x + dx ) < ( R - t ) * ( R - t ) ) {
						double yy = Math.sqrt( Math.abs( ( R - t ) * ( R - t ) - ( x + dx )
								* ( x + dx ) ) );
						// out.println( y + " -> " + yy );
						area += dx * Math.abs( yy - y );
						dy -= yy - y;
						y = yy;
					} else {
						dx = Math.sqrt( Math.abs( ( R - t ) * ( R - t ) - y * y ) ) - x;
						if ( dx < 0 ) {
							dx = 0;
						}
					}
					// out
					// .println( i + " " + j + " " + x + " " + dx + " " + y + " " + dy + " "
					// + area );
					area += 0.5 * ( R - t ) * ( R - t )
							* ( f( ( x + dx ) / ( R - t ) ) - f( x / ( R - t ) ) ) - y * dx;
					// out.println( area );
				}
			}
			out.println( "Case #" + test + ": " + ( 1.0 - area * 4 / ( Math.PI * R * R ) ) );
		}
	}

	public static void main( String[] args ) throws IOException {
		Main solution = new Main();
		solution.open();
		solution.run();
		solution.close();
	}
}
