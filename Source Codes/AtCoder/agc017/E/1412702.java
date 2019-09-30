import java.io.*;
import java.util.*;

public class Main {

	void addEdge(int v, int u, int[] deg) {
//		 System.err.println(v + " " + u);
		deg[v]--;
		deg[u]++;
	}
	
	int[] p;
	boolean[] hadEdge;
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	void unite(int a, int b) {
		a = get(a);
		b = get(b);
		hadEdge[a] = hadEdge[b] = true;
		if (a != b) {
			p[b] = a;
		}
	}

	boolean fast(int n, int h, int[] as, int[] bs, int[] cs, int[] ds) {
		int[] deg = new int[2 * (h + 1)];

		p = new int[2 * h + 2];
		hadEdge = new boolean[2 * h + 2];
		for (int i = 0; i < p.length; i++) {
			p[i] = i;
		}
		
		for (int i = 0; i < n; i++) {
			int a = as[i];
			int b = bs[i];
			int c = cs[i];
			int d = ds[i];

			int from;
			if (c == 0) {
				from = h + 1 + a;
			} else {
				from = c;
			}

			int to;
			if (d == 0) {
				to = b;
			} else {
				to = h + 1 + d;
			}

			addEdge(from, to, deg);
			unite(from, to);
		}

//		System.err.println(Arrays.toString(deg));
//		
//		boolean allZero = false;
//		for (int x : deg) {
//			allZero &= x == 0;
//		}

//		if (allZero) {
//			return false;
//		}
		
		HashSet<Integer> setEdges = new HashSet<>();
		
		for (int i = 0; i < 2 * h + 2; i++) {
			if (deg[i] > 0) {
				setEdges.add(get(i));
			}
		}
		
		int shouldBe = 0;
		for (int i = 0; i < 2 * h + 2; i++) {
			if (get(i) == i && hadEdge[i]) {
				shouldBe++;
			}
		}
		
		if (shouldBe != setEdges.size()) {
			return false;
		}

		for (int i = 0; i <= h; i++) {
			if (deg[i] < 0) {
				return false;
			}
		}

		for (int i = h + 1; i <= 2 * h + 1; i++) {
			if (deg[i] > 0) {
				return false;
			}
		}

		return true;
	}

	void submit() {
		int n = nextInt();
		int h = nextInt();

		int[] as = new int[n];

		int[] bs = new int[n];
		int[] cs = new int[n];
		int[] ds = new int[n];

		for (int i = 0; i < n; i++) {
			as[i] = nextInt();
			bs[i] = nextInt();
			cs[i] = nextInt();
			ds[i] = nextInt();
		}

		out.println(fast(n, h, as, bs, cs, ds) ? "YES" : "NO");
//		out.println(slow(n, h, as, bs, cs, ds) ? "YES" : "NO");
	}
	
	boolean slow(int n, int h, int[] as, int[] bs, int[] cs, int[] ds) {
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		
		outer: do {
			if (cs[p[0]] != 0) {
				continue outer;
			}
			for (int i = 0; i < n - 1; i++) {
				int l = p[i];
				int r = p[i + 1];
				
				if (ds[l] != 0 && cs[r] != 0) {
					continue outer;
				}
				
				if (ds[l] != 0 && as[r] != ds[l]) {
					continue outer;
				}
				
				if (cs[r] != 0 && bs[l] != cs[r]) {
					continue outer;
				}
			}
			
			
			if (ds[p[n - 1]] != 0) {
				continue outer;
			}
			
			return true;
		} while (nextPermutation(p));
		
		
		return false;
	}
	
	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		
		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}


	void preCalc() {

	}

	static final int B = 4;
	
	void stress() {
		for (int tst = 0;;tst++) {
			int n = rand(1, B);
			int h = rand(1, B);
			
			int[] as = new int[n];
			int[] bs = new int[n];
			int[] cs = new int[n];
			int[] ds = new int[n];
			
			for (int i = 0; i < n; i++) {
				as[i] = rand(1, h);
				bs[i] = rand(1, h);
				cs[i] = rand(0, h - as[i]);
				ds[i] = rand(0, h - bs[i]);
			}
			
			boolean fast = fast(n, h, as, bs, cs, ds);
			boolean slow = slow(n, h, as, bs, cs, ds);
			if (fast != slow) {
				System.err.println(n + " " + h);
				System.err.println(Arrays.toString(as));
				System.err.println(Arrays.toString(bs));
				System.err.println(Arrays.toString(cs));
				System.err.println(Arrays.toString(ds));
				throw new AssertionError();
			}
			
			System.err.println("test " + tst);
		}
	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		 stress();
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