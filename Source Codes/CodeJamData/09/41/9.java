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
			int[] a = new int[n];
			for ( int i = 0; i < n; i ++ ) {
				String s = in.next();
				a[i] = s.lastIndexOf( "1" );
			}
			int r = 0;
			for ( int i = 0; i < n - 1; i ++ ) {
				int j = i;
				while ( a[j] > i ) {
					j ++;
				}
				r += j - i;
				int t = a[j];
				while ( j > i ) {
					a[j] = a[j - 1];
					j --;
				}
				a[i] = t;
			}
			out.println( "Case #" + test + ": " + r );
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
