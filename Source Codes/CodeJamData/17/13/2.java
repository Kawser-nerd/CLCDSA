import java.io.*;
import java.util.*;
import java.math.*;

public class Trogdor implements Runnable {

	public static void main(String[] args) {
		new Thread(new Trogdor()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(255);
		}
	}

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

	long nextLond() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "c";

	class State {
		public State(int hd2, int ad2, int hk2, int ak2, int i) {
			hd = hd2;
			ad = ad2;
			hk = hk2;
			ak = ak2;
			steps = i;
		}

		int hd, ad, hk, ak;
		int steps;

		public String getString() {
			return hd + ":" + ad + ":" + hk + ":" + ak;
		}
	}

	private void solve() {
		int tests = nextInt();
		nextTest: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int hd = nextInt();
			int ad = nextInt();
			int hk = nextInt();
			int ak = nextInt();
			int b = nextInt();
			int d = nextInt();
			Queue<State> q = new ArrayDeque<>();
			State s = new State(hd, ad, hk, ak, 0);
			q.add(s);
			HashMap<String, State> hm = new HashMap<>();
			hm.put(s.getString(), s);
			while (!q.isEmpty()) {
				s = q.poll();
				if (s.hk <= s.ad) {
					out.println(s.steps + 1);
					continue nextTest;
				}
				if (s.hd > s.ak) {
					// attack
					State sn = new State(s.hd - s.ak, s.ad, s.hk - s.ad, s.ak, s.steps + 1);
					if (!hm.containsKey(sn.getString())) {
						hm.put(sn.getString(), sn);
						q.add(sn);
					}
					// buff
					sn = new State(s.hd - s.ak, s.ad + b, s.hk , s.ak, s.steps + 1);
					if (!hm.containsKey(sn.getString())) {
						hm.put(sn.getString(), sn);
						q.add(sn);
					}
				}
				// heal
				State sn = new State(hd - s.ak, s.ad, s.hk, s.ak, s.steps + 1);
				if (sn.hd > 0 && !hm.containsKey(sn.getString())) {
					hm.put(sn.getString(), sn);
					q.add(sn);
				}
				// debuff
				sn = new State(s.hd - Math.max(0, s.ak - d), s.ad, s.hk, Math.max(0, s.ak - d), s.steps + 1);
				if (sn.hd > 0 && !hm.containsKey(sn.getString())) {
					hm.put(sn.getString(), sn);
					q.add(sn);
				}
			}
			out.println("IMPOSSIBLE");
		}
	}

}
