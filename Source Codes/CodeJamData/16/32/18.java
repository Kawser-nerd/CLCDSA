import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
//		br = new BufferedReader(new FileReader("B-small.in"));
//		pw = new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
		int cnttest = nextInt();
		for (int test = 1; test <= cnttest; test++) {
			pw.print("Case #"+test+": ");
			int n = nextInt();
			long m = nextLong();
			int[][]a = new int[n+1][n+1];
			long M = m;
			int pow = 0;
			while (M % 2==0) {
				M /= 2;
				pow++;
			}
			boolean ok = true;
			if (M==1) {
				if (pow+2 > n)
					ok = false;
				else {
					for (int i = 1; i <= pow+1; i++) {
						for (int j = 1; j < i; j++) {
							a[j][i] = 1;
						}
					}
					for (int i = 1; i <= pow+1; i++) {
						a[i][n] = 1;
					}
				}
			}
			else {
				for (int i = 1; i < n; i++) {
					for (int j = 1; j < i; j++) {
						a[j][i] = 1;
					}
				}
				for (int i = 0; i < 60; i++) {
					if ((m & (1l << i)) != 0) {
						if (i+2 >= n) {
							ok = false;
							break;
						}
						a[i+2][n] = 1;
					}
				}
			}
			if (ok) {
				pw.println("POSSIBLE");
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						pw.print(a[i][j]);
					}
					pw.println();
				}
			}
			else
				pw.println("IMPOSSIBLE");
		}
		pw.close();
	}


	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
