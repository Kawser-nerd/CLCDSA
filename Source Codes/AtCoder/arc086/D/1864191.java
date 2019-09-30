import java.io.*;
import java.util.*;

public class Main {

	int compare(State was, State now) {
		long diff = was.a[0] - now.a[0];
		for (int i = 0; i < was.a.length; i++) {
			if (was.a[i] - now.a[i] != diff) {
				return 0;
			}
		}

		if (was.a[0] >= now.a[0]
				&& was.a[0] + was.spent <= now.a[0] + now.spent) {
			return 1;
		}
		return 0;
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void submit() {
		int n = nextInt();
		long k = nextLong();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		Arrays.sort(a);
		out.println(go(a, k));
	}

	void preCalc() {

	}

	void stress() {

	}

	boolean kindaSame(State was, State now) {
		long diff = was.a[0] - now.a[0];
		for (int i = 0; i < was.a.length; i++) {
			if (was.a[i] - now.a[i] != diff) {
				return false;
			}
		}
		return true;
	}

	static class State {
		long[] a;
		int spent;

		public State(long[] a, int spent) {
			this.a = a;
			this.spent = spent;
		}

		@Override
		public String toString() {
			return "(" + Arrays.toString(a) + ", " + spent + ")";
		}

		State div() {
			long[] newA = a.clone();
			for (int i = 0; i < newA.length; i++) {
				newA[i] /= 2;
			}
			return new State(newA, spent + 1);
		}

		State divSub() {
			if (a[0] == 0) {
				return null;
			}
			long[] newA = a.clone();
			for (int i = 0; i < newA.length; i++) {
				newA[i] = (a[i] - 1) / 2;
			}
			return new State(newA, spent + 2);
		}
	}

	static final int P = 1_000_000_007;

	static class Arr {
		long[] diff;

		public Arr(long[] vals) {
			diff = new long[vals.length - 1];
			for (int i = 0; i < diff.length; i++) {
				diff[i] = vals[i + 1] - vals[i];
			}
		}

		@Override
		public int hashCode() {
			return Arrays.hashCode(diff);
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Arr other = (Arr) obj;
			if (!Arrays.equals(diff, other.diff))
				return false;
			return true;
		}

	}

	int go(long[] a, long k) {
		// a is sorted
		ArrayDeque<State> q = new ArrayDeque<>();
		State init = new State(a, 0);
		q.add(init);
		ArrayList<State> seen = new ArrayList<>();

		HashMap<Arr, ArrayList<Long>> map = new HashMap<>();

		while (!q.isEmpty()) {
			State now = q.poll();
			boolean bad = false;
			for (State was : seen) {
				if (compare(was, now) == 1) {
					bad = true;
					break;
				}
			}
			if (bad) {
				continue;
			}
			seen.add(now);

			Arr arr = new Arr(now.a);
			ArrayList<Long> lst = map.get(arr);
			if (lst == null) {
				lst = new ArrayList<>();
				map.put(arr, lst);
			}
			lst.add(now.a[0]);
			lst.add((long) now.spent);

			State tmp = now.div();
			if (tmp != null) {
				q.add(tmp);
			}
			tmp = now.divSub();
			if (tmp != null) {
				q.add(tmp);
			}
		}

		int ans = 0;
		for (ArrayList<Long> lst : map.values()) {
			ans += solveGroup(lst, k);
			if (ans >= P) {
				ans -= P;
			}
		}
		return ans;
	}

	static class Event implements Comparable<Event> {
		long x;
		int delta;

		public Event(long x, int delta) {
			this.x = x;
			this.delta = delta;
		}

		@Override
		public int compareTo(Event o) {
			return Long.compare(x, o.x);
		}
	}

	int solveGroup(ArrayList<Long> lst, long k) {
		Event[] a = new Event[lst.size()];
		int ptr = 0;
		for (int i = 0; i < lst.size(); i += 2) {
			long init = lst.get(i);
			long used = lst.get(i + 1);
			if (used > k) {
				continue;
			}
			long low = Math.max(init - (k - used), 0);
			long high = init;
			a[ptr++] = new Event(low, 1);
			a[ptr++] = new Event(high + 1, -1);
		}
		Arrays.sort(a, 0, ptr);
		int sum = 0;
		int ret = 0;
		for (int i = 0; i < ptr - 1; i++) {
			sum += a[i].delta;
			if (sum > 0) {
				ret += (int) ((a[i + 1].x - a[i].x) % P);
				if (ret >= P) {
					ret -= P;
				}
			}
		}
		return ret;
	}

	void test() {
		// go(new long[] { 10, 13, 22 });
		// go(new long[]{228344079825412349L, 478465001534875275L,
		// 398048921164061989L, 329102208281783917L});
		// go(new long[]{3, 4});
		int C = 100;
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, C);
			}
			go(a, 0);
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
//		test();
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