import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class D implements Runnable {

	private PrintWriter out;

	final String file = "D-large";
	Random rnd = new Random(42);

    static int[] union(int[] a, int[] b) {
        int ns = 0;
        for (int i = 0, j = 0; i < a.length || j < b.length; ) {
            ns++;
            if (i < a.length && j < b.length) {
                if (a[i] == b[j]) {
                    i++;
                    j++;
                } else if (a[i] < b[j]) {
                    ++i;
                } else {
                    ++j;
                }
            } else if (i < a.length) {
                ++i;
            } else {
                ++j;
            }
        }
        int[] c = new int[ns];
        ns = 0;
        for (int i = 0, j = 0; i < a.length || j < b.length; ) {
            if (i < a.length && j < b.length) {
                if (a[i] == b[j]) {
                    c[ns++] = a[i++];
                    j++;
                } else if (a[i] < b[j]) {
                    c[ns++] = a[i++];
                } else {
                    c[ns++] = b[j++];
                }
            } else if (i < a.length) {
                c[ns++] = a[i++];
            } else {
                c[ns++] = b[j++];
            }
        }
        return c;
    }

    static boolean subset(int[] a, int[] b) {
        for (int i = 0, j = 0; i < a.length || j < b.length; ) {
            if (i < a.length && j < b.length) {
                if (a[i] == b[j]) {
                    i++;
                    j++;
                } else if (a[i] < b[j]) {
                    return false;
                } else {
                    ++j;
                }
            } else {
                return i == a.length;
            }
        }
        return true;
    }

    static boolean intersect(int[] a, int[] b) {
        for (int i = 0, j = 0; i < a.length || j < b.length; ) {
            if (i < a.length && j < b.length) {
                if (a[i] == b[j]) {
                    return true;
                } else if (a[i] < b[j]) {
                    ++i;
                } else {
                    ++j;
                }
            } else {
                return false;
            }
        }
        return false;
    }

	static class InputData {
        int n, d, k;
        int[][] a;

		InputData(FastReader in) throws IOException {
		    n = in.nextInt();
            d = in.nextInt();
            k = in.nextInt();
            a = new int[n][d];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < d; ++j) {
                    a[i][j] = in.nextInt();
                }
                Arrays.sort(a[i]);
            }
		}

        int size, sizePow;
        int[][][] sets;

		void solve(PrintWriter out) {
            size = 1;
            sizePow = 0;
            while (size < n) {
                size *= 2;
                sizePow++;
            }
		    sets = new int[2 * size - 1][][];
            for (int i = 0; i < size; ++i) {
                if (i < n) {
                    sets[size - 1 + i] = new int[d][1];
                    for (int j = 0; j < d; ++j) {
                        sets[size - 1 + i][j][0] = a[i][j];
                    }
                } else {
                    sets[size - 1 + i] = new int[0][];
                }
            }
            int maxSize = d;
            for (int i = size - 2; i >= 0; --i) {
                sets[i] = combine(sets[2 * i + 1], sets[2 * i + 2]);
                maxSize = Math.max(maxSize, sets[i].length);
            }
            System.err.println(maxSize);
            int ans = 0, ansFrom = -1;
            for (int i = 0; i < n; ++i) {
//                if (i % 1000 == 0) {
//                    System.err.println(i + " " + recs + " " + recs2);
//                }
                int cur = rec(i, new int[0], 0);
                if (cur > ans) {
                    ansFrom = i;
                    ans = cur;
                }
            }
            out.println(ansFrom + " " + (ansFrom + ans - 1));
            System.err.println(recs + " " + recs2);
		}

        int recs = 0, recs2 = 0;

        private int rec(int i, int[] set, int level) {
            if (i == n) {
                return 0;
            }
            recs2++;
            do {
                if (!intersect(a[i], set)) {
                    break;
                }
                while ((i & ((1 << (level + 1)) - 1)) == 0) {
                    ++level;
                }
                int level0 = level;
                while (level >= 0) {
//                    System.err.println(sizePow + " " + level + " " + i);
                    if ((i & ((1 << level) - 1)) == 0) {
                        int at = (1 << (sizePow - level)) - 1 + (i >> level);
                        int step = 1 << level;
                        for (int[] stepSet : sets[at]) {
                            if (subset(stepSet, set)) {
                                if ((i & ((1 << (level + 1)) - 1)) == 0) {
                                    for (int[] stepSet1 : sets[at + 1]) {
                                        if (subset(stepSet1, set)) {
                                            System.err.println(i + " " + level + " " + level0 + " " + at + " " + Arrays.deepToString(sets[at]) + " " + Arrays.deepToString(sets[at + 1]) + " " + Arrays.deepToString(sets[(at - 1) / 2]) + " " + Arrays.toString(set));
                                            throw new AssertionError();
                                        }
                                    }
                                }
                                //System.err.println(i + " " + step + " " + Arrays.deepToString(stepSets) + " " + Arrays.toString(set));
                                return step + rec(i + step, set, level);
                            }
                        }
                    }
                    level--;
                }
            } while (false);
            recs++;
            if (set.length < k) {
                int ret = 0;
                for (int j = 0; j < d; ++j) {
                    int[] set1 = Arrays.copyOf(set, set.length + 1);
                    set1[set.length] = a[i][j];
                    Arrays.sort(set1);
                    ret = Math.max(ret, 1 + rec(i + 1, set1, level));
                }
                return ret;
            }
            return 0;
        }

        private int[][] combine(int[][] u, int[][] v) {
            int[][] w = new int[u.length * v.length][];
            for (int i = 0; i < u.length; ++i) {
                for (int j = 0; j < v.length; ++j) {
                    w[i * v.length + j] = union(u[i], v[j]);
                }
            }
            Arrays.sort(w, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if (o1.length == o2.length) {
                        for (int i = 0; i < o1.length; ++i) {
                            if (o1[i] != o2[i]) {
                                return o1[i] - o2[i];
                            }
                        }
                    }
                    return o1.length - o2.length;
                }
            });
            if (w.length == 0 || w[0].length > k) {
                return new int[0][];
            }
            int size = 1;
            loop: for (int i = 1; i < w.length; ++i) {
                if (w[i].length > k) {
                    continue;
                }
                for (int j = 0; j < i; ++j) {
                    if (subset(w[j], w[i])) {
                        continue loop;
                    }
                }
                if (!Arrays.equals(w[i - 1], w[i])) {
                    size++;
                }
            }
            int[][] ret = new int[size][];
            ret[0] = w[0];
            loop: for (int i = 1, jj = 1; i < w.length; ++i) {
                if (w[i].length > k) {
                    continue;
                }
                for (int j = 0; j < i; ++j) {
                    if (subset(w[j], w[i])) {
                        continue loop;
                    }
                }
                if (!Arrays.equals(w[i - 1], w[i])) {
                    ret[jj++] = w[i];
                }
            }
            return ret;
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
//			Future<String>[] ts = new Future[tests];
//			for (int test = 0; test < tests; ++test) {
//				ts[test] = service.submit(new Solver(new InputData(in)));
//			}
			for (int test = 0; test < tests; ++test) {
				Solver solver = new Solver(new InputData(in));
				System.err.println("Test " + test + " " + solver.data.n);
				out.print("Case #" + (test + 1) + ": ");
				out.print(solver.call());
			}
			service.shutdown();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

    static BigInteger bi(long value) {
        return BigInteger.valueOf(value);
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

        BigInteger nextBigInteger() throws IOException {
            return new BigInteger(next());
        }
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new D().run();
	}

}