import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SolB3 {

	public static void main(String[] args) {
		try {
			new SolB3().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine(), " \n\t/");
			} catch (IOException e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() {
		return Long.parseLong(nextToken());
	}
	
	String FNAME = "B-large";
	
	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
            int n = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            int ans = 0;

            for (int i = 0; i < n; i++) {
                int imin = 0;
                for (int j = 0; j < n - i; j++) {
                    if (a[j] < a[imin]) {
                        imin = j;
                    }
                }
                ans += Math.min(imin, n - 1 - i - imin);
                for (int j = imin; j < n - i - 1; j++) {
                    a[j] = a[j + 1];
                }
            }

            out.println(ans);
        }
	}
}
