import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	
	public int sq(int x1, int y1, int x2, int y2, int x3, int y3 ){
		return (x1-x2)*(y2-y3) - (y1-y2) * (x2-x3);
	}
	
	public void solve() throws Exception {
		int n = iread();
		int m = iread();
		long square = lread();
		int x1 = 0;
		int y1 = 0;
		while( (n-1) * m >= square ) {
			n--;
		}
		while(n* (m-1) >= square ) {
			m--;
		}
		if(n*m < square ){
			out.write("IMPOSSIBLE\n");
			return;
		}
		for(int x2 = n; x2 >= 0; x2--) {
			mm: for(int y2 = 0; y2 <= m; y2++) {
				int x3 = 0;
				int y3 = 0;
				while(x3 <= n ){
					while( sq(x1,y1,x2,y2,x3,y3) < square) {
						y3++;
						if(y3 > m) continue mm;
					}
					if( sq(x1,y1,x2,y2,x3,y3) == square ){ 
						out.write(x1 + " " + y1 + " " + x2 + " " + y2 + " " + x3 + " " + y3 + "\n");
						return;
					}
					x3++;
				}
			}
		}
		System.out.println(n+ " " +m + " " + square);
		throw new NullPointerException();
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
