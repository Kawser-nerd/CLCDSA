import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class gcj2D implements Runnable {

	private PrintWriter out;
	
	final String file = "D-large";
	Random rnd = new Random(42);

    final static long MOD = 1000000007;

    static long[][] c = new long[1001][1001];
    static long[] fact = new long[1001];
    static {
        fact[0] = 1;
        for (int i = 1; i < fact.length; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        for (int i = 0; i < c.length; ++i) {
            for (int j = 1; j < i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
            c[i][0] = c[i][i] = 1;
        }
    }

    static long modPow(long x, long pow) {
        long r = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = (r * x) % MOD;
            }
            pow /= 2;
            x = (x * x) % MOD;
        }
        return r;
    }

    static class Node {
        Node[] nodes = new Node[26];
        int leaves = 0, leaves0 = 0;

        int solve1(int n) {
            int ret = Math.min(n, leaves);
            for (Node nn : nodes) {
                if (nn != null) {
                    ret += nn.solve1(n);
                }
            }
            return ret;
        }

        long solve2(int n) {
            if (leaves < n) {
                return c[n][leaves] * fact[leaves] % MOD;
            }
            long ret = leaves0 == 0 ? 1 : n;
            boolean hasLarge = false;
            for (Node sn : nodes) {
                if (sn == null) {
                    continue;
                }
                ret = (ret * sn.solve2(n)) % MOD;
                if (sn.leaves >= n) {
                    hasLarge = true;
                }
            }
            if (leaves0 >= n) {
                hasLarge = true;
                ret = ret * c[leaves0][n] % MOD;
            }
            if (hasLarge) {
                return ret;
            }
            long[] d = new long[n + 1];
            d[leaves0] = leaves0 == 0 ? 1 : n;
            for (Node sn : nodes) {
                if (sn == null) {
                    continue;
                }
                long[] d1 = new long[n + 1];
                for (int i = 0; i <= n; ++i) {
                    if (d[i] == 0) {
                        continue;
                    }
                    for (int j = Math.max(0, sn.leaves - i); j <= sn.leaves && j <= n - i; ++j) {
                        long cur = c[i][sn.leaves - j] * c[n - i][j] % MOD;
                        cur = cur * fact[sn.leaves] % MOD;
                        d1[i + j] = (d1[i + j] + d[i] * cur) % MOD;
                    }
                }
                d = d1;
            }
            return d[n] % MOD;
        }
    }

	static class InputData {

        int n;
        String[] ss;

		InputData(FastReader in) throws IOException {
            int m = in.nextInt();
            n = in.nextInt();
            ss = new String[m];
            for (int i = 0; i < m; ++i) {
                ss[i] = in.next();
            }
		}
		
		void solve(PrintWriter out) {
            Node root = new Node();
            for (String s : ss) {
                Node cur = root;
                for (char c : s.toCharArray()) {
                    cur.leaves++;
                    if (cur.nodes[c - 'A'] == null) {
                        cur.nodes[c - 'A'] = new Node();
                    }
                    cur = cur.nodes[c - 'A'];
                }
                cur.leaves++;
                cur.leaves0++;
            }
            int ans1 = root.solve1(n);
            long ans2 = root.solve2(n);
//            long ans3 = solveSlow(ans1);
            out.println(ans1 + " " + ans2);
//            if (ans2 != ans3) {
//                out.println(Arrays.toString(ss) + " " + n);
//            }
		}

        private long solveSlow(int ans1) {
            int[] col = new int[ss.length];
            return rec(0, col, ans1);
        }

        private long rec(int u, int[] col, int total) {
            if (u == col.length) {
                Node[] roots = new Node[n];
                for (int i = 0; i < n; ++i) {
                    roots[i] = new Node();
                }
                int cur = n;
                for (int i = 0; i < col.length; ++i) {
                    cur += addString(roots[col[i]], ss[i]);
                }
                for (int i = 0; i < n; ++i) {
                    if (roots[i].leaves == 0) {
                        return 0;
                    }
                }
                return total == cur ? 1 : 0;
            }
            long ret = 0;
            for (col[u] = 0; col[u] < n; ++col[u]) {
                ret += rec(u + 1, col, total);
            }
            return ret;
        }
    }

    static int addString(Node root, String s) {
        root.leaves++;
        int ret = 0;
        Node cur = root;
        for (char c : s.toCharArray()) {
            if (cur.nodes[c - 'A'] == null) {
                cur.nodes[c - 'A'] = new Node();
                ret++;
            }
            cur = cur.nodes[c - 'A'];
        }
        return ret;
    }
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new gcj2D().run();
	}
	
}
