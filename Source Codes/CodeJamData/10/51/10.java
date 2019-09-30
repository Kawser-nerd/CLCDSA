import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class A implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	public long diff(long a, long b, long modulo) {
		return (a + modulo - b) % modulo;
	}
	
	public boolean isPrime(long x) {
		for( long t = 2; t*t <= x; t++ ) {
			if( x % t == 0 ) return false;
		}
		return true;
	}
	
	public long gcd(long x, long y) {
		if( y == 0 ) return x;
		return gcd(y, x % y);
	}
	
	public void solve() throws Exception 
	{
		int d = Integer.parseInt(readword());
		long base = 1;
		for( int i = 0; i < d; i++ ) {
			base *= 10;
		}
		int n = Integer.parseInt(readword());
		long a[] = new long[n];
		long max = 0;
		for( int i = 0; i < n; i++ ) {
			a[i] = Integer.parseInt(readword());
			if( a[i] > max ) max = a[i];
		}
		if( n == 1 ) {
			out.write("I don't know.\n");
			return;
		}
		long ans = -1;
		for( long P = max + 1; P < base; P++) {
			if( !isPrime(P) ) continue;
			for( long A = 0; A < P; A++) {
				boolean fl = true;
				long diff = (P * P + a[1] - a[0] * A) % P;
				for( int i = 1; i < n; i++ ) {
					if( (P * P + a[i] - a[i-1] * A) % P != diff ) {
						fl = false;
						break;
					}
				}
				if( fl ) {
					long tmp = (a[n-1] * A + diff) % P;
					if( ans == -1 ) {
						ans = tmp;
					} else if( ans != tmp ) {
						out.write("I don't know.\n");
						return;
					}
				}
			}
		}
		out.write(ans + "\n");
	}
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) c = in.read();
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			c = in.read();
		}
		return bld.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(this.getClass().getName() + ".in"));
			out = new BufferedWriter(new FileWriter(this.getClass().getName() + ".out"));
			int tn = Integer.parseInt(readword());
			for(int i = 0; i < tn; i++ ) {
				System.out.println(i);
				out.write("Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		new Thread(new A()).start();
	}
}
