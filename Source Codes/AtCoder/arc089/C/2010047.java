import java.io.*;
import java.util.*;

public class Main {
	
	static final int INF = Integer.MAX_VALUE / 3;

	void submit() {
		int a = nextInt();
		int b = nextInt();
		int[][] d = new int[a + 1][b + 1];
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				d[i][j] = nextInt();
			}
		}
		
		int[][] x = new int[X + 1][X + 1];
		for (int[] row : x) {
			Arrays.fill(row, -INF);
		}
		for (int ca = 0; ca <= X; ca++) {
			for (int cb = 0; ca + cb <= X; cb++) {
				for (int i = 1; i <= a; i++) {
					for (int j = 1; j <= b; j++) {
						x[ca][cb] = Math.max(x[ca][cb], d[i][j] - ca * i - cb * j);
					}
				}
			}
		}
		
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				int got = Integer.MAX_VALUE;
				for (int ca = 0; ca <= 100; ca++) {
					for (int cb = 0; ca + cb <= X; cb++) {
						if (0 <= x[ca][cb] && x[ca][cb] <= X) {
							got = Math.min(got, x[ca][cb] + ca * i + cb * j);
						}
					}
				}
				if (got != d[i][j]) {
					out.println("Impossible");
					return;
				}
			}
		}
		
		int m = 2 * X;
		
		for (int ca = 0; ca <= X; ca++) {
			for (int cb = 0; ca + cb <= X; cb++) {
				if (0 <= x[ca][cb] && x[ca][cb] <= X) {
					m++;
				}
			}
		}
		
		out.println("Possible");
		int n = 2 * (X + 1);
		
		out.println(n + " " + m);
		
		for (int i = 0; i < X; i++) {
			out.println((i + 1) + " " + (i + 2) + " X");
			out.println((X + i + 3) + " " + (X + i + 2) + " Y");
		}
		
		for (int ca = 0; ca <= X; ca++) {
			for (int cb = 0; ca + cb <= X; cb++) {
				if (0 <= x[ca][cb] && x[ca][cb] <= X) {
//					m++;
					out.println((ca + 1) + " " + (X + 2 + cb) + " " + x[ca][cb]);
				}
			}
		}
		
		out.println(1 + " " + (X + 2));
	}
	
	static final int X = 100;

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}