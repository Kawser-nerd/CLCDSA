import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Ball {
		int c, w, id;

		public Ball(int c, int w, int id) {
			this.c = c;
			this.w = w;
			this.id = id;
		}
	}

	static Comparator<Ball> byC = new Comparator<Ball>() {

		@Override
		public int compare(Ball o1, Ball o2) {
			if (o1.c != o2.c) {
				return o1.c < o2.c ? -1 : 1;
			}
			return Integer.compare(o1.w, o2.w);
		}
	};

	static Comparator<Ball> byW = new Comparator<Ball>() {

		@Override
		public int compare(Ball o1, Ball o2) {
			return Integer.compare(o1.w, o2.w);
		}
	};

	int[] rank;
	int[] p;
	int[] sz;

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	void unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return;
		}

		if (rank[v] == rank[u]) {
			rank[v]++;
		} else if (rank[v] < rank[u]) {
			int tmp = v;
			v = u;
			u = tmp;
		}

		p[u] = v;
		sz[v] += sz[u];
	}

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		int y = nextInt();
		
		int[] cols = new int[n];
		
		Ball[] a = new Ball[n];
		for (int i = 0; i < n; i++) {
			cols[i] = nextInt();
			int w = nextInt();
			a[i] = new Ball(cols[i], w, i);
		}
		
		Arrays.sort(a, byC);
		
		rank = new int[n];
		p = new int[n];
		sz = new int[n];
		Arrays.fill(sz, 1);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && a[i].c == a[j].c) {
				j++;
			}
			
			for (int k = i + 1; k < j; k++) {
				if (a[i].w + a[k].w <= x) {
					unite(a[i].id, a[k].id);
				}
			}
			
			i = j;
		}
		
		Arrays.sort(a, byW);
		for (int i = 1; i < n; i++) {
			if (a[0].c != a[i].c && a[0].w + a[i].w <= y) {
				unite(a[0].id, a[i].id);
			}
		}
		
		int oth = 0;
		while (oth < n && a[0].c == a[oth].c) {
			oth++;
		}
		
		if (oth != n) {
			for (int i = 0; i < n; i++) {
				if (a[oth].c != a[i].c && a[oth].w + a[i].w <= y) {
					unite(a[oth].id, a[i].id);
				}
			}
		}
		
		int[] fact = new int[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (int)((long)i * fact[i - 1] % P);
		}
		
		List<Integer>[] comp = new List[n];
		for (int i = 0; i < n; i++) {
			if (get(i) == i) {
				comp[i] = new ArrayList<>(sz[i]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			comp[get(i)].add(cols[i]);
		}
		
		int ret = 1;
		for (List<Integer> c : comp) {
			if (c == null) {
				continue;
			}
//			System.err.println(c);
			ret = (int) ((long)ret * fact[c.size()] % P);
			Collections.sort(c);
			for (int i = 0; i < c.size(); ) {
				int j = i;
				while (j < c.size() && c.get(i).equals(c.get(j))) {
					j++;
				}
				
				ret = (int)((long)ret * inv(fact[j - i]) % P);
				i = j;
			}
		}
		
		out.println(ret);
	}

	static int inv(int x) {
		return x == 1 ? 1 : P - (int) ((long) (P / x) * inv(P % x) % P);
	}

	static final int P = 1_000_000_007;

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.