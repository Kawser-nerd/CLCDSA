import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class B implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	public void solve() throws Exception 
	{
		int n = Integer.parseInt(readword());
		int k = Integer.parseInt(readword());
		int b = Integer.parseInt(readword());
		int t = Integer.parseInt(readword());
		int x[] = new int[n];
		int v[] = new int[n];
		for( int i = 0; i < n; i++ ) {
			x[i] = Integer.parseInt(readword());
		}
		for( int i = 0; i < n; i++ ) {
			v[i] = Integer.parseInt(readword());
		}
		int count = 0;
		int answer = 0;
		for( int i = n - 1; i >= 0; i--) {
			if( count == k ) break;
			if( b - x[i] <= v[i] * t ) {
				answer += n - i - 1 - count;
				count++;
			}
		}
		if( count != k ) {
			out.write("IMPOSSIBLE\n");
		} else {
			out.write(answer + "\n");
		}
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
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(this.getClass().getName() + ".in"));
			out = new BufferedWriter(new FileWriter(this.getClass().getName() + ".out"));
			int tn = Integer.parseInt(readword());
			for( int i = 0; i < tn; i++ ) {
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
		new Thread(new B()).start();
	}
}
