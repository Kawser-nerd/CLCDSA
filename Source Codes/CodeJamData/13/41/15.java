import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);
	static long N;
	static int M;
	static long MOD = 1000002013;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			System.out.println("Case #" + t + ": " + solve());
		}
	}

	static int solve() {
		N = sc.nextInt();
		M = sc.nextInt();
		Event[] ev = new Event[2 * M];
		long sum = 0;
		for (int i = 0; i < M; ++i) {
			int o = sc.nextInt();
			int e = sc.nextInt();
			int p = sc.nextInt();
			ev[i * 2] = new Event(0, o, p);
			ev[i * 2 + 1] = new Event(1, e, p);
			sum += fee(o, e) * p;
			sum %= MOD;
		}
		Arrays.sort(ev);
		long sum2 = 0;
		ArrayList<State> sts = new ArrayList<State>();
		for (int i = 0; i < 2 * M; ++i) {
			Event e = ev[i];
			if (e.type == 0) {
				sts.add(new State(e.t, e.p));
				continue;
			}
			int rest = e.p;
			long pay = 0;
			while (true) {
				State st = sts.get(sts.size() - 1);
				if (st.c >= rest) {
					st.c -= rest;
					pay += (fee(st.time, e.t) * rest) % MOD;
					break;
				} else {
					rest -= st.c;
					pay += (fee(st.time, e.t) * st.c) % MOD;
					sts.remove(sts.size() - 1);
				}
			}
			sum2 += pay;
			sum2 %= MOD;
		}
		long ans = sum - sum2;
		if (ans < 0) ans += MOD;
		return (int) (ans % MOD);
	}

	static long fee(int s, int e) {
		return ((N + N - (e - s - 1)) * (e - s) / 2) % MOD;
	}

	static class State {
		int time, c;

		public State(int st, int c) {
			this.time = st;
			this.c = c;
		}

	}

	static class Event implements Comparable<Event> {
		int type;
		int t, p;

		public Event(int type, int t, int p) {
			this.type = type;
			this.t = t;
			this.p = p;
		}

		public int compareTo(Event o) {
			if (this.t != o.t) return this.t - o.t;
			return this.type - o.type;
		}
	}

}