import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeMap;

public class A implements Runnable {

	public void solve() throws IOException {
		int tn = in.nextInt();
		for ( int test = 1; test <= tn; test ++ ) {
            double l = in.nextInt();
            int s = in.nextInt();
            int r = in.nextInt();
            double t = in.nextDouble();
            int n = in.nextInt();
            int[] b = new int[n];
            int[] e = new int[n];
            int[] w = new int[n];
            for ( int i = 0; i < n; i ++ ) {
                b[i] = in.nextInt();
                e[i] = in.nextInt();
                w[i] = in.nextInt();
            }
            TreeMap<Integer, Double> distWithSpeed = new TreeMap<Integer, Double>();
            distWithSpeed.put( s, l );
            for ( int i = 0; i < n; i ++ ) {
                distWithSpeed.put( s, distWithSpeed.get( s ) - ( e[i] - b[i] ) );
                add( distWithSpeed, w[i] + s, 1.0 * e[i] - b[i] );
            }
//            for ( Integer speed : distWithSpeed.keySet() ) {
//                out.println( speed + ": " + distWithSpeed.get( speed ) );
//            }
//            out.println();
            TreeMap<Integer, Double> timeWithSpeed = new TreeMap<Integer, Double>();
            for ( Integer speed : distWithSpeed.keySet() ) {
                double d = distWithSpeed.get( speed );
                double time = d / ( speed + r - s );
                if ( t * ( speed + r - s ) > d ) {
                    add( timeWithSpeed, speed + r - s, time );
                    t -= time;
                } else {
                    add( timeWithSpeed, speed + r - s, t );
                    add( timeWithSpeed, speed, ( d - ( speed + r - s ) * t ) / speed );
                    t = 0;
                }
            }
//            for ( Integer speed : timeWithSpeed.keySet() ) {
//                out.println( speed + ": " + timeWithSpeed.get( speed ) );
//            }
//            out.println();
            double res = 0.0;
            for ( Integer speed : timeWithSpeed.keySet() ) {
                res += timeWithSpeed.get( speed );
            }
			out.println( "Case #" + test + ": " + res );
		}
	}

    private void add( TreeMap<Integer, Double> map, Integer key, Double value ) {
        if ( ! map.containsKey( key ) ) {
            map.put( key, value );
        } else {
            map.put( key, map.get( key ) + value );
        }
    }

	public Scanner in;

	public PrintWriter out;

	A() throws IOException {
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
		new Thread( new A() ).start();
	}
}
