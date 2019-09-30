import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ3C implements Runnable {

	private PrintWriter out;

//    final String file = "C-sample";
	final String file = "C-small-attempt1";
	static Random rnd = new Random(42);

	static class InputData {

        int n;
        int[] id;
        boolean[] enter;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
//            n = 1000;
            id = new int[n];
            enter = new boolean[n];
            for (int i = 0; i < n; ++i) {
                enter[i] = in.next().equals("E");
                id[i] = in.nextInt();
//                enter[i] = rnd.nextBoolean();
//                id[i] = rnd.nextBoolean() ? rnd.nextInt(1000) : 0;
            }
		}
		
		void solve(PrintWriter out) {
            int ans0 = -2;
            if (n <= 15) {
                ans0 = solveSlow();
                if (ans0 == -1) {
                    out.println("CRIME TIME");
                } else {
                    out.println(ans0);
                }
                return;
            }
            ArrayList<Integer> zeros = new ArrayList<Integer>();
            ArrayList<Integer> leaves = new ArrayList<Integer>();
            int conflicts = 0, ends = 0;
            int enterZeros = 0;
            for (int i = 0; i < n; ++i) {
                if (id[i] == 0) {
                    zeros.add(i);
                    if (enter[i]) {
                        enterZeros++;
                    }
                } else {
                    int j = i + 1;
                    while (j < n && id[i] != id[j]) {
                        ++j;
                    }
                    if (j < n && enter[i] == enter[j]) {
                        ++conflicts;
                        if (!enter[i]) {
                            --enterZeros;
                        }
                    }
                    if (j == n && enter[i]) {
                        ends++;
                    }
                    if (!enter[i]) {
                        j = i - 1;
                        while (j >= 0 && id[i] != id[j]) {
                            --j;
                        }
                        if (j < 0) {
                            leaves.add(i);
                        }
                    }
                }
            }
            int gn = zeros.size() + 2 * conflicts + ends + leaves.size() + 2;
            int[][] g = new int[gn][gn];
            int s = gn - 2, t = gn - 1;
            for (int i = 0; i < zeros.size(); ++i) {
                if (enter[zeros.get(i)]) {
                    for (int j = i + 1; j < zeros.size(); ++j) {
                        if (!enter[zeros.get(j)]) {
                            g[i][j] = 1;
                        }
                    }
                    for (int j = 0; j < leaves.size(); ++j) {
                        if (zeros.get(i) < leaves.get(j)) {
                            g[i][zeros.size() + 2 * conflicts + ends + j] = 1;
                        }
                    }
                    g[s][i] = 1;
                } else {
                    g[i][t] = 1;
                }
            }
            for (int i = 0; i < leaves.size(); ++i) {
                g[zeros.size() + 2 * conflicts + ends + i][t] = 1;
            }
            int conflicts0 = conflicts;
            conflicts = 0;
            ends = 0;
            for (int i = 0; i < n; ++i) {
                if (id[i] != 0) {
                    int j = i + 1;
                    while (j < n && id[i] != id[j]) {
                        ++j;
                    }
                    if (j < n && enter[i] == enter[j]) {
                        for (int z = 0; z < zeros.size(); ++z) {
                            if (i < zeros.get(z) && zeros.get(z) < j && enter[zeros.get(z)] != enter[i]) {
                                g[zeros.size() + 2 * conflicts + 0][z] = 1;
                                g[z][zeros.size() + 2 * conflicts + 1] = 1;
                            }
                        }
                        g[zeros.size() + 2 * conflicts + 1][t] = 1;
                        conflicts++;
                    }
                    if (j == n && enter[i]) {
                        for (int z = 0; z < zeros.size(); ++z) {
                            if (i < zeros.get(z) && !enter[zeros.get(z)]) {
                                g[zeros.size() + 2 * conflicts0 + ends][z] = 1;
                            }
                        }
                        ends++;
                    }
                }
            }
            System.out.println(zeros + " " + conflicts + " " + ends + " " + leaves + " " + enterZeros);
            for (int i = 0; i < gn; ++i) {
                for (int j = 0; j < gn; ++j) {
                    System.out.print(g[i][j] + " ");
                }
                System.out.println();
            }
            boolean[] col = new boolean[gn];
            for (int i = zeros.size(); i < zeros.size() + conflicts; ++i) {
                if (!dfs(i, t, g, col)) {
                    if (ans0 != -2 && ans0 != -1) {
                        throw new AssertionError();
                    }
                    out.println("CRIME TIME");
                    return;
                }
                Arrays.fill(col, false);
            }
            int ans = ends + enterZeros;
            for (int i = zeros.size() + 2 * conflicts; i < zeros.size() + 2 * conflicts + ends; ++i) {
                if (dfs(i, t, g, col)) {
                    ans--;
                }
                Arrays.fill(col, false);
            }
            while (dfs(s, t, g, col)) {
                ans--;
                Arrays.fill(col, false);
            }
            System.out.println();
            for (int i = 0; i < gn; ++i) {
                for (int j = 0; j < gn; ++j) {
                    System.out.print(g[i][j] + " ");
                }
                System.out.println();
            }
            if (ans0 != -2 && ans0 != ans) {
                throw new AssertionError(ans0 + " " + ans);
            }
            out.println(ans);
		}

        private int solveSlow() {
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int i = 0; i < n; ++i) {
                if (id[i] == 0) {
                    continue;
                }
                if (!map.containsKey(id[i])) {
                    map.put(id[i], map.size());
                }
            }
            boolean[] d = new boolean[1 << n];
            Arrays.fill(d, true);
            for (int i = 0; i < n; ++i) {
                boolean[] d1 = new boolean[1 << n];
                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (!d[mask]) {
                        continue;
                    }
                    for (int j = id[i] == 0 ? 0 : map.get(id[i]); j < (id[i] == 0 ? n : map.get(id[i]) + 1); ++j) {
                        boolean state = (mask & (1 << j)) != 0;
                        if (state != enter[i]) {
                            d1[mask ^ (1 << j)] = true;
                        }
                    }
                }
                d = d1;
            }
            int ret = -1;
            for (int i = 0; i < 1 << n; ++i) {
                if (d[i]) {
                    int cur = Integer.bitCount(i);
                    if (ret == -1 || cur < ret) {
                        ret = cur;
                    }
                }
            }
            return ret;
        }

        private boolean dfs(int s, int t, int[][] g, boolean[] col) {
            if (s == t) {
                return true;
            }
            if (col[s]) {
                return false;
            }
            col[s] = true;
            for (int i = g.length - 1; i >= 0; --i) {
                if (g[s][i] > 0 && dfs(i, t, g, col)) {
                    g[s][i]--;
                    g[i][s]++;
                    return true;
                }
            }
            return false;
        }
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
		new GCJ3C().run();
	}
	
}
