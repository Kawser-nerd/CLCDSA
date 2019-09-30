import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			System.err.println(test);
			out.println("Case #" + test + ": " + solve());
		}
	}

	private int solve() throws IOException {
		int numTribes = nextInt();
		List<Event> events = new ArrayList<Event>();
		for (int i = 0; i < numTribes; i++) {
			int d = nextInt();
			int n = nextInt();
			int w = nextInt();
			int e = nextInt();
			int s = nextInt();
			int deltaD = nextInt();
			int deltaP = nextInt();
			int deltaS = nextInt();
			for (int j = 0; j < n; j++) {
				Event ev = new Event();
				ev.time = d;
				ev.l = w;
				ev.r = e - 1;
				ev.strength = s;
				events.add(ev);
				d += deltaD;
				w += deltaP;
				e += deltaP;
				s += deltaS;
			}
		}
		Collections.sort(events);
		//int r1 = dummy(events);
		int r2 = solveFast(events);
		return r2;
	}

	private int solveFast(List<Event> events) {
		int numInteresting = repaint(events);		
		Tree tree = new SmartTree(numInteresting);
		int res = 0;
		int i = 0;
		while (i < events.size()) {
			int j = i;
			while (j < events.size() && events.get(i).time == events.get(j).time) {
				++j;
			}
			--j;
			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				if (tree.getMin(e.l, e.r) < e.strength) {
					++res;
				}
			}			
			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				tree.update(e.l, e.r, e.strength);				
			}
			i = j + 1;
		}
		return res;
	}

	private int repaint(List<Event> events) {
		TreeSet<Integer> interestring = new TreeSet<Integer>();
		for (Event e : events) {
			for (int delta = -1; delta <= 1; delta++) {			
				interestring.add(e.l + delta);
				interestring.add(e.r + delta);
			}
		}
		int[] xs = new int[interestring.size()];
		int numXs = 0;
		for (int x : interestring) {
			xs[numXs++] = x;
		}
		for (Event e : events) {
			e.l = Arrays.binarySearch(xs, e.l);
			e.r = Arrays.binarySearch(xs, e.r);
		}
		return xs.length;
	}

	private int dummy(List<Event> events) {
		Map<Integer, Integer> wall = new HashMap<Integer, Integer>();
		int res = 0;
		int i = 0;
		while (i < events.size()) {
			int j = i;
			while (j < events.size() && events.get(i).time == events.get(j).time) {
				++j;
			}
			--j;

			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				for (int z = e.l; z <= e.r; z++) {
					Integer level = wall.get(z);
					if (level == null) {
						level = 0;
					}
					if (level < e.strength) {
						++res;
						break;
					}
				}
			}
			
			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				for (int z = e.l; z <= e.r; z++) {
					Integer level = wall.get(z);
					if (level == null) {
						level = 0;
					}
					if (level < e.strength) {
						level = e.strength;
					}
					wall.put(z, level);
				}
			}
			i = j + 1;
		}
		return res;
	}

	class Event implements Comparable<Event> {
		int time;
		int strength;
		int l, r;
		
		public int compareTo(Event o) {
			if (time != o.time) return time - o.time;
			if (strength != o.strength) return strength - o.strength;
			if (l != o.l) return l - o.l;
			if (r != o.r) return r - o.r;
			return 0;
		}
	}

	interface Tree {
		public void update(int l, int r, int val);
		public int getMin(int l, int r);
	}

	class DummyTree implements Tree {
		int[] a;
		DummyTree(int n) {
			a = new int[n];
		}
		public void update(int l, int r, int val) {
			for (int i = l; i <= r; i++) {
				a[i] = Math.max(a[i], val);
			}
		}		
		public int getMin(int l, int r) {
			int res = a[l];
			for (int i = l; i <= r; i++) {
				res = Math.min(res, a[i]);
			}
			return res;
		}
	}

	class SmartTree implements Tree {
		int[] a;
		int n;

		SmartTree(int n) {
			this.n = n;
			int k = 1;
			while (k <= n) {
				k *= 2;
			}
			a = new int[2 * k];
		}
		public void update(int l, int r, int val) {
			update(0, l, r, 0, n - 1, val);
		}
		private void update(int root, int l, int r, int L, int R, int val) {
			if (l > r || l > R || L > r || L > R) return;
			int M = L + (R - L) / 2;			
			if (l == L && r == R) {
				a[root] = Math.max(a[root], val);
			} else {				
				a[2 * root + 1] = Math.max(a[2 * root + 1], a[root]);
				a[2 * root + 2] = Math.max(a[2 * root + 2], a[root]);
				update(2 * root + 1, l, Math.min(r, M), L, M, val);
				update(2 * root + 2, Math.max(l, M + 1), r, M + 1, R, val);
				int u = a[2 * root + 1];
				int v = a[2 * root + 2];
				a[root] = Math.max(a[root], Math.min(u, v));
			}
		}
		public int getMin(int l, int r) {
			return getMin(0, l, r, 0, n - 1);
		}
		private int getMin(int root, int l, int r, int L, int R) {
			if (l > r || l > R || L > r || L > R) return Integer.MAX_VALUE;
			int M = L + (R - L) / 2;
			if (l == L && r == R) {
				return a[root];
			} else {
				a[2 * root + 1] = Math.max(a[2 * root + 1], a[root]);
				a[2 * root + 2] = Math.max(a[2 * root + 2], a[root]);
				int u = getMin(2 * root + 1, l, Math.min(r, M), L, M);
				int v = getMin(2 * root + 2, Math.max(l, M + 1), r, M + 1, R);
				return Math.min(u, v);
			}
		}
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter(new FileWriter("C-large.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
