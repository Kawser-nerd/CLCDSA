import java.util.*;
import java.io.*;

public class Main {
	
	void solve() {
		int n=  in.nextInt();
		int[] zeros = new int[n + 1];
		int[] ones = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			int x = in.nextInt();
			zeros[i] = zeros[i - 1];
			ones[i] = ones[i - 1];
			if (x == 0) {
				zeros[i]++;
			} else {
				ones[i]++;
			}
		}
		
		int q = in.nextInt();
		List<Query>[] left = new List[n + 1], right = new List[n + 1];
		for (int i = 0; i <= n; i++) {
			left[i] = new ArrayList<>();
			right[i] = new ArrayList<>();
		}
		Query[] qs = new Query[q];
		for (int i = 0; i < q; i++) {
			qs[i] = new Query(in.nextInt(), in.nextInt(), i);
			left[qs[i].l].add(qs[i]);
			right[qs[i].r].add(qs[i]);
		}
		
		int[] ans = new int[q];

		SegmentTree treeZ = new SegmentTree(n + 1);
		SegmentTree treeO = new SegmentTree(n + 1);
		
		int result = ones[n];
		for (int l = 1; l <= n; l++) {
			
			for (Query query : left[l]) {
				ans[query.i] = zeros[query.r] - zeros[query.l - 1] + ones[query.l - 1];
				
				ans[query.i] = Math.min(ans[query.i], treeZ.get(query.l, query.r) + zeros[query.r]);
				
				ans[query.i] = Math.min(ans[query.i], treeO.get(0, query.l) + zeros[query.r] - zeros[query.l - 1] + ones[query.l - 1]);
				
				result = Math.min(result, ans[query.i] + ones[n] - ones[query.r]);
			}
			
			for (Query query : left[l]) {
				treeZ.set(query.r, ans[query.i] - zeros[query.r]);
				treeO.set(query.r, ans[query.i] - ones[query.r]);
			}
		}
		out.println(result);
	}
	
	int INF = Integer.MAX_VALUE / 3;
	
	class SegmentTree {
		int[] min;
		int size;
		public SegmentTree(int n) {
			min = new int[4 * n];
			size = n;
			Arrays.fill(min, INF);
		}
		
		void set(int pos, int val) {
			set(0, size, pos, val, 0);
		}
		
		void set(int l, int r, int pos, int val, int i) {
			if (l + 1 == r) {
				min[i] = Math.min(min[i], val);
				return;
			}
			int m = (l + r) >>> 1;
			if (pos < m) {
				set(l, m, pos, val, 2 * i + 1);
			} else {
				set(m, r, pos, val, 2 * i + 2);
			}
			min[i] = Math.min(min[2 * i + 1], min[2 * i + 2]);
		}
		
		int get(int left, int right) {
			return get(0, size, left, right, 0);
		}
		
		int get(int l, int r, int left, int right, int i) {
			if (left <= l && r <= right) {
				return min[i];
			} else if (right <= l || r <= left) {
				return INF;
			} else {
				int m = (l + r) >>> 1;
				return Math.min(get(l, m, left, right, 2 * i + 1), get(m, r, left, right, 2 * i + 2));
			}
		}
	}
	
	class Query {
		int l, r, i;

		public Query(int l, int r, int i) {
			super();
			this.l = l;
			this.r = r;
			this.i = i;
		}

		@Override
		public String toString() {
			return "Query [l=" + l + ", r=" + r + ", i=" + i + "]";
		}
		
		
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.