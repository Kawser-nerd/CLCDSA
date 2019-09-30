import java.io.*;
import java.util.*;

public class Main {

	static class Item {
		long b, c;

		public Item(long b, long c, int id) {
			this.b = b;
			this.c = c;
			this.id = id;
		}

		int id;

		@Override
		public String toString() {
			return "Item [b=" + b + ", c=" + c + ", id=" + id + "]";
		}
	}

	static Comparator<Item> byC = new Comparator<Item>() {

		@Override
		public int compare(Item o1, Item o2) {
			return -Long.compare(o1.c, o2.c);
		}
	};

	static Comparator<Item> byCMinusB = new Comparator<Item>() {

		@Override
		public int compare(Item o1, Item o2) {
			return Long.compare(o1.c - o1.b, o2.c - o2.b);
		}
	};

	static Comparator<Item> byB = new Comparator<Item>() {

		@Override
		public int compare(Item o1, Item o2) {
			if (o1.b != o2.b) {
				return o1.b < o2.b ? -1 : 1;
			}
			return Integer.compare(o1.id, o2.id);
		}
	};

	void submit() {
		int x = nextInt();
		int y = nextInt();
		int z = nextInt();
		int n = x + y + z;
		long[] as = new long[n];
		long[] bs = new long[n];
		long[] cs = new long[n];

		for (int i = 0; i < n; i++) {
			as[i] = nextLong();
			bs[i] = nextLong();
			cs[i] = nextLong();
		}

		Item[] a = new Item[n];

		long base = 0;
		for (int i = 0; i < n; i++) {
			base += as[i];
			a[i] = new Item(bs[i] - as[i], cs[i] - as[i], i);
		}

		Arrays.sort(a, byC);

		PriorityQueue<Item> head = new PriorityQueue<>(byCMinusB);
		long sumHeadB = 0;
		long sumHeadC = 0;

		for (int i = 0; i < z; i++) {
			head.add(a[i]);
			sumHeadC += a[i].c;
		}

		TreeSet<Item> tail = new TreeSet<>(byB);
		for (int i = z; i < n; i++) {
			tail.add(a[i]);
		}

		while (tail.size() > y) {
			tail.remove(tail.first());
		}

		long tailB = 0;
		for (Item it : tail) {
			tailB += it.b;
		}

		long ans = Long.MIN_VALUE;

		for (int i = z - 1; i < y + z; i++) {
			if (i != z - 1) {
				head.add(a[i]);
				sumHeadC += a[i].c;

				Item pop = head.poll();
				sumHeadC -= pop.c;
				sumHeadB += pop.b;

			}

			ans = Math.max(ans, sumHeadB + sumHeadC + tailB);

			if (i != y + z - 1) {
				if (tail.remove(a[i + 1])) {
					tailB -= a[i + 1].b;
				}
				while (tail.size() > y + z - 2 - i) {
					Item rem = tail.first();
					tailB -= rem.b;
					tail.remove(rem);
				}
			}
		}

		out.println(base + ans);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
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