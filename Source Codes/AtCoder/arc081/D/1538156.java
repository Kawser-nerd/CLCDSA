import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	private static final boolean local = false;
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter output;
	//char c = line.nextToken().charAt(0);

	private static void openFile() throws IOException {
		if (local) {
			String inp = "C:/Users/ztrong/Desktop/AndroidStudioProjects/Java/src/main/java/input.txt";
			String out = "C:/Users/ztrong/Desktop/AndroidStudioProjects/Java/src/main/java/output.txt";
			br = new BufferedReader(new InputStreamReader(new FileInputStream(inp)));
			output = new PrintWriter(new FileOutputStream(out));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
			output = new PrintWriter(System.out);
		}
	}

	private static String _next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	private static int nextInt() {
		return Integer.parseInt(_next());
	}

	private static long nextLong() {
		return Long.parseLong(_next());
	}

	private static double nextDouble() {
		return Double.parseDouble(_next());
	}

	private static String nextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}

	private static final int maxN = (int) 2e3 + 5;
	private static final int maxM = (int) 1e6 + 5;
	private static final int inf = (int) 1e9 + 7;

	private static int N, M;
	private static String[] s = new String[maxN];
	private static int[] h = new int[maxN];
	private static int[] stack = new int[maxN];
	private static int top;
	private static int[] lef = new int[maxN];
	private static int[] rig = new int[maxN];

	private static void init() {

	}

	private static void enter() throws IOException {
		N = nextInt(); M = nextInt();
		for (int i = 1; i <= N; ++i) {
			s[i] = nextLine();
			s[i] = '!' + s[i];
		}
	}

	private static boolean ok(int i, int j) {
		if (j > M) return true;
		if (i == 1) return true;
		int num = ((s[i - 1].charAt(j - 1) - '#') + (s[i - 1].charAt(j) - '#')
		+ (s[i].charAt(j - 1) - '#') + (s[i].charAt(j) - '#'));
		return num % 2 == 0;
	}

	private static void solve() throws IOException {
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			h[1] = h[1] + 1;
			for (int j = 2; j <= M + 1; ++j) {
				if (ok(i, j)) {
					h[j] += 1;
				}
				else {
					h[j] = 1;
				}
			}

			top = 0;

			for (int j = 1; j <= M + 1; ++j) {
				while (top > 0 && h[stack[top]] >= h[j]) --top;
				if (top == 0) lef[j] = 1;
				else lef[j] = stack[top];
				stack[++top] = j;
			}

			top = 0;

			for (int j = M + 1; j >= 1; --j) {
				while (top > 0 && h[stack[top]] >= h[j]) --top;
				if (top == 0) rig[j] = M + 1;
				else rig[j] = stack[top];
				stack[++top] = j;
			}

			for (int j = 1; j <= M + 1; ++j) {
				res = Math.max(res, h[j] * (rig[j] - lef[j]));
			}
		}

		output.println(res);
	}

	public static void main(String[] args) throws IOException {
		openFile();
		init();
		enter();
		solve();
		output.close();
	}
}