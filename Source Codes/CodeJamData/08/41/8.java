import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	
	int n;
	int best[][];
	boolean canChange[];
	int value[];
	
	public void rec(int node) {
		if(node * 2 + 1 > n) {
			best[value[node]][node] = 0;
			best[(value[node]+1)%2][node] = 1000000;
			return;
		}
		
		int nv1 = node * 2;
		int nv2 = node * 2 + 1;
		rec(nv1);
		rec(nv2);
		best[0][node] = 1000000;
		best[1][node] = 1000000;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				for( int k = 0; k < 2; k++) {
					int dx = 0;
					if( value[node] != k ) {
						if(canChange[node]) dx = 1; else dx = 1000000;
					}
					if( k == 1 ) {
						best[i*j][node] = Math.min(best[i*j][node], best[i][nv1] + best[j][nv2] + dx );
					} else {
						int nxt = i+j;
						if(nxt > 1) nxt = 1;
						best[nxt][node] = Math.min(best[nxt][node], best[i][nv1] + best[j][nv2] + dx);
					}
				}
			}
		}
	}
	
	public void solve() throws Exception {
		n = iread();
		int need = iread();
		best = new int[2][n+1];
		canChange = new boolean[n+1];
		value = new int[n+1];
		for( int i = 1 ; i <= n; i++ ){
			if( i * 2 + 1 <= n ) {
				value[i] = iread();
				canChange[i] = iread() == 1;
			} else {
				value[i] = iread();
			}
		}
		rec(1);
		if( best[need][1] > 500000 ) {
			out.write("IMPOSSIBLE\n");
		} else {
			out.write(best[need][1] + "\n");
		}
	}
	
	public int iread() throws IOException {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws IOException {
		return Double.parseDouble(readword());
	}
	
	public long lread() throws IOException {
		return Long.parseLong(readword());
	}
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) {
			c = in.read();
		}
		if( c < 0 ) return "";
		StringBuilder builder = new StringBuilder();
		while( c > ' ' ) {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader("input.txt"));
			out = new BufferedWriter( new FileWriter("output.txt"));
			int tn = iread();
			for(int tc = 1; tc <= tn; tc++) {
				out.write("Case #" + tc + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}

}
