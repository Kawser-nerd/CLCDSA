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

	private static final int maxN = (int) 2e5 + 5;
	private static final int maxM = (int) 1e6 + 5;
	private static final int maxC = (int) 'z' - 'a' + 1;
	private static final int inf = (int) 1e9 + 7;

	private static int N;
	private static String s;
	private static int[] pos, dp, trace;
	static {
		pos = new int[maxC];
		dp = new int[maxN];
		trace = new int[maxN];
	}

	private static void init() {
		for (int i = 0; i < maxN; ++i) {
			dp[i] = inf;
		}
	}

	private static void enter() throws IOException {
		s = nextLine();
		N = s.length();
		s = '!' + s;
	}

	private static void solve() throws IOException {
		for (int i = N; i >= 0; --i) {
			boolean fl = false;
			for (int nex = 0; nex <= 'z' - 'a'; ++nex) {
				if (pos[nex] == 0) {
					dp[i] = 1;
					trace[i] = nex;
					fl = true;
					break;
				}
			}

			if (!fl) {
				for (int nex = 0; nex <= 'z' - 'a'; ++nex) {
					if (dp[i] > dp[pos[nex]] + 1) {
						dp[i] = dp[pos[nex]] + 1;
						trace[i] = pos[nex];
					}
				}
			}

			if (i > 0)
				pos[s.charAt(i) - 'a'] = i;
		}
	}

	private static void doTrace() {
		int ind = 0;
		while (dp[ind] >= 1) {
			if (dp[ind] == 1) {
				output.print((char) (trace[ind] + 'a'));
				break;
			}
			else {
				output.print(s.charAt(trace[ind]));
			}
			ind = trace[ind];
		}
	}

	public static void main(String[] args) throws IOException {
		openFile();
		init();
		enter();
		solve();
		doTrace();
		output.close();
	}
}