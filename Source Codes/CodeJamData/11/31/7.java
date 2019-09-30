import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	private void solve() throws IOException {
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.println("Case #" + test + ":");
			
			int N = nextInt();
			int M = nextInt();
			
			char[][] F = new char[N][M];
			
			for(int i = 0; i < N; i++) {
				String S = nextToken();
				
				for(int j = 0; j < M; j++) {
					F[i][j] = S.charAt(j);
				}
			}
			
			for(int i = 0; i < N - 1; i++) {
				for(int j = 0; j < M - 1; j++) {
					if(F[i][j] == '#' && F[i + 1][j] == '#' && F[i][j + 1] == '#' && F[i + 1][j + 1] == '#') {
						F[i][j] = '/';
						F[i][j + 1] = '\\';
						F[i + 1][j] = '\\';
						F[i + 1][j + 1] = '/';
					}
					
				}
			}
			
			boolean ok = true;
			
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(F[i][j] == '#') {
						ok = false;
					}
				}
			}
			
			if(!ok) {
				out.println("Impossible");
			} else {
				for(int i = 0; i < N; i++) {
					for(int j = 0; j < M; j++) {
						out.print(F[i][j]);
					}
					out.print("\n");
				}
			}
		}
	}
	
	public static void main(String[] args) {
		new A().run();
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
