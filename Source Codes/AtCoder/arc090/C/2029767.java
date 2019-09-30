import java.io.*;
import java.util.*;

public class Main {

	int[] head;
	int[] next;
	int[] to;
	int[] len;

	void addEdge(int v, int u, int l, int i) {
		to[i] = u;
		next[i] = head[v];
		len[i] = l;
		head[v] = i;
	}

	int n;

	void submit() {
		n = nextInt();
		int m = nextInt();
		int s = nextInt() - 1;
		int t = nextInt() - 1;

		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[2 * m];
		to = new int[2 * m];
		len = new int[2 * m];

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int l = nextInt();

			addEdge(v, u, l, 2 * i);
			addEdge(u, v, l, 2 * i + 1);
		}

		long[][] zs = dijk(s);
		long[][] zt = dijk(t);

		long[] ds = zs[0];
		long[] ws = zs[1];

		long[] dt = zt[0];
		long[] wt = zt[1];
		
//		System.err.println(Arrays.toString(ds));
//		System.err.println(Arrays.toString(ws));
//		System.err.println(Arrays.toString(dt));
//		System.err.println(Arrays.toString(wt));
		

		long pathLen = ds[t];

		ArrayList<Integer> lst = new ArrayList<>();

		for (int v = 0; v < n; v++) {
			if (ds[v] + dt[v] == pathLen && ds[v] == dt[v]) {
				lst.add((int) (ws[v] * wt[v] % P));
			}
		}

		for (int v = 0; v < n; v++) {
			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				int edge = len[e];
				if (ds[v] + dt[u] + edge != pathLen) {
					continue;
				}
				if (ds[v] * 2 >= pathLen) {
					continue;
				}
				if (dt[u] * 2 >= pathLen) {
					continue;
				}
				lst.add((int) (ws[v] * wt[u] % P));
			}
		}
		
		int sum = 0;
		int sum2 = 0;
		
		for (int x : lst) {
			sum += x;
			if (sum >= P) {
				sum -= P;
			}
			sum2 += (int)((long)x * x % P);
			if (sum2 >= P) {
				sum2 -= P;
			}
		}
		
		int ret = (int)((long)sum * sum % P);
		ret -= sum2;
		if (ret < 0) {
			ret += P;
		}
		
		out.println(ret);
	}

	static class Distance implements Comparable<Distance> {
		int v;
		long dist;

		public Distance(int v, long dist) {
			this.v = v;
			this.dist = dist;
		}

		@Override
		public int compareTo(Distance o) {
			return Long.compare(dist, o.dist);
		}
	}

	static final long INF = Long.MAX_VALUE / 10;

	static final int P = 1_000_000_007;

	long[][] dijk(int v) {
		long[] d = new long[n];
		long[] ways = new long[n];
		Arrays.fill(d, INF);
		d[v] = 0;
		ways[v] = 1;
		PriorityQueue<Distance> pq = new PriorityQueue<>();
		pq.add(new Distance(v, d[v]));

		while (!pq.isEmpty()) {
			Distance tmp = pq.poll();
			if (d[tmp.v] != tmp.dist) {
				continue;
			}

			v = tmp.v;

			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				int edge = len[e];
				if (d[u] > d[v] + edge) {
					ways[u] = ways[v];
					d[u] = d[v] + edge;
					pq.add(new Distance(u, d[u]));
				} else if (d[u] == d[v] + edge) {
					ways[u] += ways[v];
					if (ways[u] >= P) {
						ways[u] -= P;
					}
				}
			}
		}

		return new long[][] { d, ways };
	}

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
		// stress();
		// test();
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