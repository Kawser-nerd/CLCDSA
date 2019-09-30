import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class SolC {

	public static void main(String[] args) {
		try {
			new SolC().run();
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
	
	String FNAME = "C-small-attempt0";
	
	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
            System.err.println("Test: " + test);
            int n = nextInt();
            char[] act = new char[n];
            int[] id = new int[n];
            int m = 0;
            HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
            for (int i = 0; i < n; i++) {
                act[i] = nextToken().charAt(0);
                int t = nextInt();
                if (t != 0) {
                    if (!hm.containsKey(t)) {
                        hm.put(t, ++m);
                    }
                    id[i] = hm.get(t);
                }
            }
            boolean[][] p = new boolean[n + 1][1 << n];
            Arrays.fill(p[0], true);
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < (1 << n); j++) {
                    if (act[i - 1] == 'E') {
                        if (id[i - 1] != 0) {
                            if ((j & (1 << (id[i - 1] - 1))) != 0) {
                                p[i][j] |= p[i - 1][j ^ (1 << (id[i - 1] - 1))];
                            }
                        } else {
                            for (int k = 0; k < n; k++) {
                                if ((j & (1 << k)) != 0) {
                                    p[i][j] |= p[i - 1][j ^ (1 << k)];
                                }
                            }
                        }
                    } else {
                        if (id[i - 1] != 0) {
                            if ((j & (1 << (id[i - 1] - 1))) == 0) {
                                p[i][j] |= p[i - 1][j ^ (1 << (id[i - 1] - 1))];
                            }
                        } else {
                            for (int k = 0; k < n; k++) {
                                if ((j & (1 << k)) == 0) {
                                    p[i][j] |= p[i - 1][j ^ (1 << k)];
                                }
                            }
                        }
                    }
                }
            }
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < p[n].length; i++) {
                if (p[n][i]) {
                    ans = Math.min(ans, Integer.bitCount(i));
                }
            }
            out.println(ans == Integer.MAX_VALUE ? "CRIME TIME" : ans);
        }
	}
}
