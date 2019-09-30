import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

	final static String FNAME = "c1";

	public Scanner in;

	public PrintWriter out;

	void open() throws IOException {
		in = new Scanner( new File( FNAME + ".in" ) );
		out = new PrintWriter( new File( FNAME + ".out" ) );
	}

	void close() throws IOException {
		out.close();
	}

	void run() {
		BigInteger two = new BigInteger( "2" );
		BigInteger l = new BigInteger( "2" ).multiply( BigInteger.TEN.pow( 35 ) );
		BigInteger r = new BigInteger( "3" ).multiply( BigInteger.TEN.pow( 35 ) );
		BigInteger p = new BigInteger( "5" ).multiply( BigInteger.TEN.pow( 70 ) );
		while ( !r.equals( l ) ) {
			BigInteger m = l.add( r ).divide( two );
			if ( m.multiply( m ).compareTo( p ) > 0 ) {
				r = m;
			} else {
				l = m.add( BigInteger.ONE );
			}
		}
		// out.println( l );
		l = l.add( new BigInteger( "3" ).multiply( BigInteger.TEN.pow( 35 ) ) );
		// out.println( l );
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
			int d = in.nextInt();
			String s = ""
					+ l.pow( d ).divide( BigInteger.TEN.pow( d * 35 ) ).remainder(
							new BigInteger( "1000" ) );
			while ( s.length() < 3 ) {
				s = '0' + s;
			}
			out.println( "Case #" + test + ": " + s );
		}
	}

	public static void main( String[] args ) throws IOException {
		new Thread() {

			public void run() {
				try {
					Main solution = new Main();
					solution.open();
					solution.run();
					solution.close();
				} catch ( Exception e ) {
					throw new RuntimeException( e );
				}
			}
		}.start();
	}
}
