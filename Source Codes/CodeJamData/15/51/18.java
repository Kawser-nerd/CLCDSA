import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	
	class Segment {
		int st, en;
		int num;

		public Segment(int st, int en, int num) {
			super();
			this.st = st;
			this.en = en;
			this.num = num;
		}
	}
	
	ArrayList<Segment> segs;
	int[] s, m;
	int[] min;
	int[] max;
	
	public void solve() throws IOException {
		segs = new ArrayList<>();
		int n = in.nextInt(), d = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		s = new int[n];
		m = new int[n];
		s[0] = in.nextInt();
		int as = in.nextInt(), cs = in.nextInt(), rs = in.nextInt();
		for (int i = 1; i < n; i++) {
			s[i] = (int) ((1L * s[i - 1] * as + cs) % rs);
		}
		m[0] = in.nextInt();
		int am = in.nextInt(), cm = in.nextInt(), rm = in.nextInt();
		for (int i = 1; i < n; i++) {
			m[i] = (int) ((1L * m[i - 1] * am + cm) % rm);
			g[m[i] % i].add(i);
		}
		min = new int[n];
		max = new int[n];
		Arrays.fill(min, s[0]);
		Arrays.fill(max, s[0]);
		for (int i = 0; i < n; i++) {
			min[i] = Math.min(min[i], s[i]);
			max[i] = Math.max(max[i], s[i]);
			segs.add(new Segment(min[i], max[i], i));
			for (int u : g[i]) {
				min[u] = Math.min(min[u], min[i]);
				max[u] = Math.max(max[u], max[i]);
			}
		}
		Collections.sort(segs, new Comparator<Segment>() {

			@Override
			public int compare(Segment o1, Segment o2) {
				return Integer.compare(o1.en, o2.en);
			}
		});
		TreeSet<Segment> now = new TreeSet<>(new Comparator<Segment>() {

			@Override
			public int compare(Segment o1, Segment o2) {
				if (o1.st != o2.st)
					return Integer.compare(o1.st, o2.st);
				return Integer.compare(o1.num, o2.num);
			}
		});
		int ans = 0;
		for (int i = 0; i < segs.size();) {
			int cur = segs.get(i).en;
			while (i < segs.size() && segs.get(i).en == cur) {
				Segment seg = segs.get(i);
				now.add(seg);
				i++;
			}
			while (now.size() > 0) {
				Segment seg = now.first();
				if (seg.st < cur - d)
					now.remove(seg);
				else
					break;
			}
			ans = Math.max(ans, now.size());
		}
		out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.out.println(i);
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new A().run();
	}
}