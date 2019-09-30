import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class B implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	final static long INF = 100000000000L;
	
	public void solve() throws Exception 
	{
		long length = Long.parseLong(readword());
		int n = Integer.parseInt(readword());
		int a[] = new int[n];
		for( int i = 0; i < n; i++ ) {
			a[i] = Integer.parseInt(readword());
		}
		Arrays.sort(a);
		int m = a[n-1];
		ArrayList<Integer> list[] = new ArrayList[m+1];
		for( int i = 0; i <= m; i++ ) {
			list[i] = new ArrayList<Integer>();
		}
		long best[] = new long[m];
		Arrays.fill(best, INF);
		if( length % m == 0 ) {
			out.write(length / m + "\n");
			return;
		}
		best[m-(int)(length % m)] = 0;
		list[0].add(m-(int)(length % m));
		for( int i = 0; i <= m; i++ ) {
			int j = 0;
			while( true ) {
				if( j >= list[i].size() ) break;
				if( best[list[i].get(j)] != i ) {
					j++;
					continue;
				}
				for( int k = 0; k < n; k++ ) {
					int cost = 1;
					if( list[i].get(j) + a[k] >= m ) {
						cost = 0;
					}
					int pos = (list[i].get(j) + a[k]) % m;
					if( best[pos] > i + cost ) {
						best[pos] = i + cost;
						list[(int)best[pos]].add(pos);
					}
				}
				j++;
			}
		}
		if( best[0] == INF ) {
			out.write("IMPOSSIBLE\n");
			return;
		}
		out.write( length / m + 1 + best[0] + "\n");
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
		new Thread(new B()).start();
	}
}
