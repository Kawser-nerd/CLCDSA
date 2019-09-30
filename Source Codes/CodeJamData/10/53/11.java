import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class C implements Runnable {
	String fileName = "C-small-attempt0";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
			System.out.println(cas + " is done.");
		}
	}

	private String solve() throws IOException {
		int n = in.nextInt();
		int[] x = new int[n];
		int[] cnt = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = in.nextInt();
			cnt[i] = in.nextInt();
		}
		Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for (int i = 0; i < x.length; ++i) {
			map.put(x[i], cnt[i]);
		}
		int res = 0;
		while (true) {
			boolean ok = true;
			for (Map.Entry<Integer, Integer> me : map.entrySet()) {
				if (me.getValue() >= 2) {
					ok = false;
					map.put(me.getKey(), me.getValue() - 2);
					if (!map.containsKey(me.getKey() - 1)) {
						map.put(me.getKey() - 1, 0);
					}
					if (!map.containsKey(me.getKey() + 1)) {
						map.put(me.getKey() + 1, 0);
					}
					map.put(me.getKey() - 1, map.get(me.getKey() - 1) + 1);
					map.put(me.getKey() + 1, map.get(me.getKey() + 1) + 1);
					break;
				}
			}
			if (ok) {
				break;
			} else {
				++res;
			}
		}
		return toString(res);
		// int total = 0;
		// for (int i = 0; i < n; ++i) {
		// x[i] = in.nextInt();
		// cnt[i] = in.nextInt();
		// total += cnt[i];
		// }
		// int min = Integer.MAX_VALUE;
		// for (int t : x) {
		// if (t < min) {
		// min = t;
		// }
		// }
		// min = -min + total + 10;
		// for (int i = 0; i < n; ++i) {
		// x[i] += min;
		// }
		// int max = Integer.MIN_VALUE;
		// for (int t : x) {
		// if (t > max) {
		// max = t;
		// }
		// }
		// max = max + total + 10;
		// int size = Integer.highestOneBit(max) * 2;
		// int[] sum = new int[size * 2];
		// for (int i = size; i < sum.length; ++i) {
		// sum[i] = 1;
		// }
		// for (int i = size - 1; i > 0; --i) {
		// sum[i] = sum[2 * i] + sum[2 * i + 1];
		// }
		// for (int i = 0; i < n; ++i) {
		// for (int j = 0; j < cnt[i]; ++j) {
		// findMin(sum, x[i]);
		// }
		// }
		// int[] where = new int[total];
		// int it = 0;
		// for (int i = size; i < sum.length; ++i) {
		// if (sum[i] == 0) {
		// where[it++] = i - size;
		// }
		// }
		// long res = 0;
		// it = 0;
		// for (int i = 0; i < n; ++i) {
		// for (int j = 0; j < cnt[i]; ++j) {
		// res += Math.abs(where[it++] - x[i]);
		// }
		// }
		// return toString(res);
	}

	private void findMin(int[] sum, int x) {
		int L = findRight(0, x, sum);
		int R = findLeft(x, sum.length - 1, sum);
		if (x - L <= R - x) {
			update(sum, L);
		} else {
			update(sum, R);
		}
	}

	private void update(int[] sum, int i) {
		i += sum.length >> 1;
		while (i != 0) {
			--sum[i];
			i >>= 1;
		}
	}

	private int findLeft(int I, int J, int[] sum) {
		int i = I + (sum.length >> 1);
		int j = J + (sum.length >> 1);
		int id = -1;
		while (i <= j) {
			if ((i & 1) != 0) {
				if (sum[i] != 0) {
					id = i;
					break;
				}
				++i;
			}
			if ((j & 1) == 0) {
				if (sum[j] != 0) {
					id = j;
				}
				--j;
			}
			i >>= 1;
			j >>= 1;
		}
		while (2 * id < sum.length) {
			if (sum[2 * id] != 0) {
				id = 2 * id;
			} else {
				id = 2 * id + 1;
			}
		}
		return id - (sum.length >> 1);
	}

	private int findRight(int I, int J, int[] sum) {
		int i = I + (sum.length >> 1);
		int j = J + (sum.length >> 1);
		int id = -1;
		while (i <= j) {
			if ((i & 1) != 0) {
				if (sum[i] != 0) {
					id = i;
				}
				++i;
			}
			if ((j & 1) == 0) {
				if (sum[j] != 0) {
					id = j;
					break;
				}
				--j;
			}
			i >>= 1;
			j >>= 1;
		}
		while (2 * id < sum.length) {
			if (sum[2 * id + 1] != 0) {
				id = 2 * id + 1;
			} else {
				id = 2 * id;
			}
		}
		return id - (sum.length >> 1);
	}

	public void run() {
		try {
			in = new Scanner(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			solution();
			in.reader.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private String toString(Object ob) {
		StringBuilder builder = new StringBuilder();
		try {
			int size = Array.getLength(ob);
			for (int i = 0; i < size; ++i) {
				if (i != 0) {
					builder.append(" ");
				}
				builder.append(Array.get(ob, i));
			}
		} catch (Exception e) {
			builder.append(ob);
		}
		return builder.toString();
	}

	private class Scanner {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader reader) {
			this.reader = new BufferedReader(reader);
			this.tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				String next = reader.readLine();
				if (next == null) {
					return false;
				}
				tokenizer = new StringTokenizer(next);
			}
			return true;
		}

		public String next() throws IOException {
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}
	}

	public static void main(String[] args) throws IOException {
		new Thread(null, new C(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
