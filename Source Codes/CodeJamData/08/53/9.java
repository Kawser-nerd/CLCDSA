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
	
	public int iread() throws IOException {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws IOException {
		return Double.parseDouble(readword());
	}
	
	int m;
	int n;
	String map[];
	public boolean isSuitable( int a, int row ){
		for( int i = 0; i < n; i++) {
			if(map[i].charAt(row) == 'x' && (a & (1<<i)) != 0 ) {
				return false;
			}
		}
		return true;
	}
	
	public boolean isCompatible( int a, int b) {
		boolean cc[] = new boolean[n];
		boolean dd[] = new boolean[n];
		for( int i = 0; i < n; i++) {
			dd[i] = (b & (1<<i)) != 0;
			cc[i] = (a & (1<<i)) != 0;
		}
		for( int i = 0; i < n; i++) {
			if( dd[i] && cc[i]) return false;
		}
		for( int i = 0; i < n-1; i++) {
			if( dd[i] && cc[i+1]) return false;
			if( dd[i+1] && cc[i]) return false;
		}
		return true;
	}
	
	public int calc(int a) {
		int res = 0;
		while( a != 0) {
			res = res + a % 2;
			a /= 2;
		}
		return res;
	}
	
	public void solve() throws Exception {
		n = iread();
		m = iread();
		int res[][] = new int[1<<n][m];
		map = new String[n];
		for( int i = 0; i < (1<<n); i++) {
			Arrays.fill(res[i], -1000000);
		}
		
		for( int i = 0; i < n; i++) map[i] = readword();
		for( int i = 0; i < (1<<n); i++) {
			if( isSuitable(i,0) ) res[i][0] = calc(i); else res[i][0] = -1000000;
		}
		
		for(int i = 1; i < m; i++) {
			for( int j = 0; j < (1<<n); j++) {
				for( int k = 0; k < (1<<n); k++) {
					if( isCompatible(j,k) && isSuitable(k,i) ) {
						res[k][i] = Math.max(res[k][i], res[j][i-1] + calc(k));
					}
				}
			}
		}
		
		int result = 0;
		for( int i = 0; i < (1<<n); i++) {
			result = Math.max(result, res[i][m-1]);
		}
		out.write(result+"\n");
	}
	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
			int n = iread();
			for( int i = 0; i < n; i++) {
				out.write("Case #" + (i+1) + ": ");
			solve();
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
