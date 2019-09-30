import java.util.*;
import java.io.*;

//import java.math.*;

public class SolC implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolC()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "C-small-attempt0";
	
	class Tribe {
		int d, n, w, e, s, dd, dp, ds;
		
		Tribe() {
			d = nextInt();
			n = nextInt();
			w = nextInt();
			e = nextInt();
			s = nextInt();
			dd = nextInt();
			dp = nextInt();
			ds = nextInt();
		}
		
		List<Attack> getAll() {
			List<Attack> ret = new ArrayList<Attack>();
			for (int i = 0; i < n; i++) {
				ret.add(new Attack(d, w, e, s));
				d += dd;
				w += dp;
				e += dp;
				s += ds;
			}
			return ret;
		}
	}
	
	class Attack implements Comparable<Attack> {
		public Attack(int d2, int w, int e, int s2) {
			d = d2;
			l = w;
			r = e;
			s = s2;
		}

		int d, l, r, s;

		@Override
		public int compareTo(Attack o) {
			return d - o.d;
		}
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			Tribe[] tr = new Tribe[n];
			ArrayList<Attack> events = new ArrayList<Attack>();
			for (int i = 0; i < n; i++) {
				tr[i] = new Tribe();
				events.addAll(tr[i].getAll());
			}
			Collections.sort(events);
			
			int MAX = 1000;
			int shift = MAX / 2;
			
			int[] h = new int[2 * MAX];
			int ans = 0;

			int i = 0;
			while (i < events.size()) {
				int day = events.get(i).d;
				int ii = i;
				while (ii < events.size() && events.get(ii).d == day) {
					Attack e = events.get(ii);
					boolean succ = false;
					for (int j = 2 * (e.l + shift); j <= 2 * (e.r + shift); j++) {
						if (h[j] < e.s) {
							succ = true;
						}
					}
					if (succ) {
						ans++;
					}
					System.err.println(e.d + " " + e.l + " "+ e.r + " " + e.s + " " + succ);
					ii++;
				}
				while (i < events.size() && events.get(i).d == day) {
					Attack e = events.get(i);
					for (int j = 2 * (e.l + shift); j <= 2 * (e.r + shift); j++) {
						h[j] = Math.max(h[j], e.s);
					}		
					i++;
				}				
			}
			System.err.println("Solved: " + test);
			System.err.println();
			out.println(ans);
		}		
	}
}
