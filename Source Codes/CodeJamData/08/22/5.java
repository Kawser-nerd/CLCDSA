import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c < ' ' ) c = in.read();
		if (c < 0) return "";
		StringBuilder builder = new StringBuilder();
		while (c > ' ') {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	public class DSU {
		int p[];
		int rank[];
		DSU(int n) {
			p = new int[n];
			for(int i = 0; i < n; i++) p[i] = i;
			rank = new int[n];
		}
		
		public int get( int v ) {
			if( p[v] == v ) return v; else return get(p[v]);
		}
		
		public void join( int v1, int v2 ) {
			int p1 = get(v1);
			int p2 = get(v2);
			if( p1 != p2 ) {
				if( rank[p1] > rank[p2] ) {
					p[p2] = p1;
				} else {
					p[p1] = p2;
					if( rank[p1] == rank[p2] ) rank[p2]++;
				}
			}
		}
	}
	
	int primes[] = new int[1000000];
	int prCount = 0;
	final static int max = 1100000;
	public void solve() throws Exception {
		long a = Long.parseLong(readword());
		long b = Long.parseLong(readword());
		DSU dsu = new DSU( (int)(b - a + 1));
		long k = Long.parseLong(readword());
		for(long i = k; i <= max; i++) {
			if(!isPrime(i)) continue;
			long current = (b / i) * i;
			while (true) {
				long current1 = current - i;
				if( current1 < a) break;
				dsu.join((int)(current-a), (int)(current1-a));
				current = current1;
			}
		}
		int result = 0;
		for(int i = 0; i <= b - a; i++) {
			if(dsu.get(i) == i) result++;
		}
		out.write(result + "\n");
	}
	
	public boolean isPrime( long n ) {
		for( int i = 2; i * i <= n; i++ ) {
			if( n % i == 0 ) return false;
		}
		return true;
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
			int tn = Integer.parseInt(readword());
			for( int i = 0; i < tn; i++ ) {
				out.write("Case #" + (i+1) + ": ");
				solve();
				out.flush();
			}
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

}
