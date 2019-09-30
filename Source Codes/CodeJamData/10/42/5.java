import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class b implements Runnable {
	BufferedReader in;
	BufferedWriter out;

	final static long INF = 1000000000000L;
	int counts[];
	int n;
	int costs[];
	long best[][];
	
	public long calc(int match, int played) {
	//	System.out.println(match);
		if( match >= (1<<n) ) {
			if( played >= counts[(1<<n)-1-(match-(1<<n))]) {
				return 0;
			} else {
				return INF;
			}
		}
		if( best[match][played] >= 0 ) {
			return best[match][played];
		}
		long x1 = calc(match*2+1, played) + calc(match*2, played);
		long x2 = calc(match*2+1, played+1) + calc(match*2, played+1) + costs[match];
		best[match][played] = Math.min(x1, x2);
		return best[match][played];
	}
	
	public void solve() throws Exception 
	{
		n = Integer.parseInt(readword());
		counts = new int[1<<n];
		for( int i = 0; i < (1<<n); i++ ) {
			counts[i] = n - Integer.parseInt(readword());
		}
		costs = new int[1<<n];
		for( int i = 0; i < (1<<n)-1; i++ ) {
			costs[(1<<n)-1-i] = Integer.parseInt(readword());
		}
		best = new long[1<<n][n+1];
		for( int i = 0; i < (1<<n); i++ ) {
			Arrays.fill(best[i], -1);
		}
		out.write(calc(1,0) + "\n");
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
		new Thread(new b()).start();
	}
}
