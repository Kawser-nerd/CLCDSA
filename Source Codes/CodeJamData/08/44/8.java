import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	
	int n;
	boolean vis[];
	int perm[];
	int result;
	String s;
	public int calc() {
	
		int res = 1;
		char lastChar = s.charAt(perm[0]);
		for(int i = 1; i < s.length(); i++) {
			if( lastChar != s.charAt(i/n*n + perm[i%n])) {
				res++;
				lastChar = s.charAt(i/n*n + perm[i%n]);
			}
		}
		return res;
	}
	
	public void rec(int dep ){
		if( dep == n ) {
			result = Math.min(result, calc() );
			return;
		}
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				vis[i] = true;
				perm[dep] = i;
				rec(dep+1);
				vis[i] = false;
			}
		}
	}
	public void solve() throws Exception {
		n = iread();
		vis = new boolean[n];
		perm = new int[n];
		s = readword();
		result = 100000000;
		rec(0);
		out.write(result + "\n");
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
