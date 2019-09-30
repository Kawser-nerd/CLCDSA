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
	
	public void solve() throws Exception {
		int n = Integer.parseInt(readword());
		int a[][] = new int[3][3];
		long A,B,C,D,x0,y0,M;
		A = Long.parseLong(readword());
		B = Long.parseLong(readword());
		C = Long.parseLong(readword());
		D = Long.parseLong(readword());
		x0 = Long.parseLong(readword());
		y0 = Long.parseLong(readword());
		M = Long.parseLong(readword());

		for( int i = 0; i < n; i++) {
			a[(int)(x0%3)][(int)(y0%3)]++;
			x0 = (A*x0+B)%M;
			y0 = (C*y0+D)%M;
		}
		
		long result = 0;
		for(int i = 0; i < 9; i++) {
			for(int j = i; j < 9; j++) {
				for(int k = j; k < 9; k++) {
					if( (i%3+j%3+k%3) % 3 != 0 ) continue;
					if((i/3+j/3+k/3) % 3 != 0) continue;
					if( i == j && j == k ) {
						long cc = a[i%3][i/3];
						result += cc*(cc-1)*(cc-2) / 6;
					} else {
						if( i == j ) {
							long cc1 = a[j%3][j/3];
							long cc2 = a[k%3][k/3];
							result += cc1 * (cc1 - 1) / 2 * cc2;
						} else {
							if( j == k ) {
								long cc1 = a[j%3][j/3];
								long cc2 = a[i%3][i/3];
								result += cc1 * (cc1 - 1) / 2 * cc2;
							} else {
								long cc1 = a[j%3][j/3];
								long cc2 = a[i%3][i/3];
								long cc3 = a[k%3][k/3];
								result += cc1 * cc2 * cc3;
							}
						}
					}
				}
			}
		}
		out.write(result + "\n");
	}
	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.txt") );
			out = new BufferedWriter(new FileWriter("output.txt"));
			int tn = Integer.parseInt(readword());
			for( int i = 0; i < tn; i++) {
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
