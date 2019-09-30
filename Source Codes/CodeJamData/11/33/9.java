import java.io.*;
import java.util.*;
import java.math.*;

public class C {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	private void solve() throws IOException {
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			
			int N = nextInt();
			long L = nextLong();
			long H = nextLong();
			
			long[] A = new long[N];
			
			for(int i = 0; i < N; i++) {
				A[i] = nextLong();
			}
			
			long result = -1;
			
			for(long C = L; C <= H; C++) {
				boolean ok = true;
				
				for(int i = 0; i < N; i++) {
					if(C % A[i] != 0 && A[i] % C != 0) {
						ok = false;
						break;
					}
				}
				
				if(ok) {
					result = C;
					break;
				}
			}
			
			if(result == -1) {
				out.println("NO");
			} else {
				out.println(result);
			}
			
			
		}
	}
	
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
		try {
			//System.setIn(new FileInputStream("input.txt"));
			//System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = null;
			
			solve();
			
			in.close();
			out.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	private String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		
		return st.nextToken();
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}
