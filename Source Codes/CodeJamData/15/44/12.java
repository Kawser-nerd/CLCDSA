import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static final long MOD = 1_000_000_007;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			int ans = solve();
			System.out.printf("Case #%d: %s\n", i, ans == -1 ? "IMPOSSIBLE" : (ans + ""));
		}
	}

	static int solve() {
		int R = sc.nextInt();
		int C = sc.nextInt();
		ArrayList<HashMap<State, Long>> memo = new ArrayList<>();
		for (int i = 0; i <= R; ++i) {
			memo.add(new HashMap<>());
		}
		State initState = new State();
		initState.last = -1;
		memo.get(0).put(initState, 1L);
		for (int i = 0; i < R; ++i) {
			for (State s : memo.get(i).keySet()) {
				long count = memo.get(i).get(s) % MOD;
				if (s.last != 0 && i + 2 <= R) {
					// type 0
					State ns = new State(s);
					ns.last = 0;
					ns.c[0]++;
					add(memo.get(i + 2), ns, count);
				}
				if (s.last <= 0) {
					// type 1
					State ns = new State(s);
					ns.last = 1;
					ns.c[1]++;
					add(memo.get(i + 1), ns, count);
				}
				if (s.last <= 0 && i + 2 <= R && C % 3 == 0) {
					// type 2
					State ns = new State(s);
					ns.last = 2;
					ns.c[2]++;
					add(memo.get(i + 2), ns, count);
				}
				if (s.last <= 0 && i + 2 <= R && C % 6 == 0) {
					// type 3
					State ns = new State(s);
					ns.last = 3;
					ns.c[3]++;
					add(memo.get(i + 2), ns, count);
				}
				if (s.last <= 0 && i + 3 <= R && C % 4 == 0) {
					// type 4
					State ns = new State(s);
					ns.last = 4;
					ns.c[4]++;
					add(memo.get(i + 3), ns, count);
				}
			}
		}
		long ans = 0;
		for (State st : memo.get(R).keySet()) {
			long count = memo.get(R).get(st);
			//			System.out.println(Arrays.toString(st.c) + " " + st.last + " " + count);
			if (st.c[3] != 0) {
				for (int i = 1; i < st.c[3]; ++i) {
					count *= 6;
					count %= MOD;
				}
				for (int i = 0; i < st.c[4]; ++i) {
					count *= 4;
					count %= MOD;
				}
				for (int i = 0; i < st.c[2]; ++i) {
					count *= 3;
					count %= MOD;
				}
			} else if (st.c[4] != 0) {
				for (int i = 1; i < st.c[4]; ++i) {
					count *= 4;
					count %= MOD;
				}
				for (int i = 0; i < st.c[2]; ++i) {
					count *= 3;
					count %= MOD;
				}
			} else if (st.c[2] != 0) {
				for (int i = 1; i < st.c[2]; ++i) {
					count *= 3;
					count %= MOD;
				}
			}
			ans += count;
			ans %= MOD;
		}

		return (int) ans;
	}

	static void add(HashMap<State, Long> map, State st, long count) {
		if (map.containsKey(st)) {
			map.put(st, map.get(st) + count);
		} else {
			map.put(st, count);
		}
	}

	static class State {
		int[] c = new int[5];
		int last;

		State() {

		}

		State(State o) {
			this.c = o.c.clone();
			this.last = o.last;
		}

		public int hashCode() {
			return Arrays.hashCode(c) * 17 + last;
		}

		public boolean equals(Object obj) {
			State o = (State) obj;
			return this.last == o.last && Arrays.equals(this.c, o.c);
		}
	}

}
