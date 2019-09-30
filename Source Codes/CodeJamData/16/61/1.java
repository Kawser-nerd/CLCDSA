import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {
	
	static class LongLongMap {

		static final long EMPTY = Long.MIN_VALUE;

		long data[] = new long[4];
		{
			data[0] = EMPTY;
			data[2] = EMPTY;
		}
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		void clear() {
			for (int i = 0; i < data.length; i += 2) {
				data[i] = EMPTY;
			}
			size = 0;
		}

		static int hash(long key) {
			long hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return (int) hash;
		}

		boolean have(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		long get(long key, long default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				long cur = data[i];
				if (cur == EMPTY) {
					continue;
				}
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == EMPTY) {
						ndata[j] = cur;
						ndata[j + 1] = data[i + 1];
						break;
					}
				}
			}
			return ndata;
		}

		void set(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] = value;
					return;
				} else if (cur == EMPTY) {
					data[i] = key;
					data[i + 1] = value;
					if (++size > capacity >> 2) {
						this.data = resize(data, capacity << 1);
					}
					return;
				}
			}
		}

		void delete(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					for (int j = i;;) {
						cur = data[j = (j - 1) & mask];
						if (cur == EMPTY) {
							data[i] = EMPTY;
							--size;
							return;
						}
						int k = hash(cur) & mask;
						if ((k >= i) ^ (k < j) ^ (i < j)) {
							data[i] = cur;
							data[i + 1] = data[j + 1];
							i = j;
						}
					}
				} else if (cur == EMPTY) {
					return;
				}
			}
		}

		void expand(int newCapacity) {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = -2;

			Iterator(long data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			long getKey() {
				return data[position];
			}

			long getValue() {
				return data[position + 1];
			}

			void advance() {
				do {
					position += 2;
				} while (position < data.length && data[position] == EMPTY);
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

	static class LongLongCounter extends LongLongMap {

		long get(long key) {
			return get(key, 0);
		}

		void set(long key, long value) {
			if (value == 0) {
				delete(key);
			} else {
				super.set(key, value);
			}
		}

		void add(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] += value;
					return;
				} else if (cur == EMPTY) {
					data[i] = key;
					data[i + 1] = value;
					if (++size > capacity >> 2) {
						this.data = resize(data, capacity << 1);
					}
					return;
				}
			}
		}
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static String r;
	static int pos;
	static final int transitions[][] = new int[11][32];

	static void addTransition(int from, int to, int digit) {
		transitions[digit][to] |= 1 << from;
	}

	static void parse() {
		while (pos < r.length()) {
			char c = r.charAt(pos);
			if (c == ')' || c == '|') {
				return;
			}
			if (c == '(') {
				int spos = pos;
				++pos;
				addTransition(spos, pos, 10);
				parse();
				if (pos >= r.length()) {
					throw new AssertionError();
				}
				c = r.charAt(pos);
				if (c == '|') {
					List<Integer> epos = new ArrayList<>();
					while (true) {
						epos.add(pos);
						++pos;
						addTransition(spos, pos, 10);
						parse();
						if (pos >= r.length()) {
							throw new AssertionError();
						}
						c = r.charAt(pos);
						if (c == '|') {
							continue;
						}
						if (c == ')') {
							break;
						}
						throw new AssertionError();
					}
					epos.add(pos);
					++pos;
					for (int p: epos) {
						addTransition(p, pos, 10);
					}
				} else if (c == ')') {
					int epos = pos;
					++pos;
					if (pos >= r.length() || r.charAt(pos) != '*') {
						throw new AssertionError();
					}
					++pos;
					addTransition(epos, pos, 10);
					addTransition(spos, pos, 10);
					addTransition(epos, spos + 1, 10);
				} else {
					throw new AssertionError();
				}
			} else if ('0' <= c && c <= '9') {
				addTransition(pos, ++pos, c - '0');
			} else {
				throw new AssertionError();
			}
		}
	}

	static long getAns(LongLongCounter states, long num) {
		long ans = 0;
		for (LongLongMap.Iterator it = states.iterator(); it.hasNext(); it.advance()) {
			int state = (int) it.getKey();
			long cnt = it.getValue();
			long cnum = num;
			while (cnum > 0) {
				int digit = (int) (cnum % 10);
				cnum /= 10;
				int nstate = 0;
				for (int i = 0; i < 32; i++) {
					if ((state & (1 << i)) != 0) {
						nstate |= transitions[digit][i];
					}
				}
				state = nstate;
			}
			if ((state & 1) != 0) {
				ans += cnt;
			}
		}
		return ans;
	}

	static void solve() throws Exception {
		long a = nextLong();
		long b = nextLong() + 1;
		r = next();
		if (r.length() > 30) {
			throw new AssertionError();
		}
		for (int t[]: transitions) {
			fill(t, 0);
		}
		pos = 0;
		parse();
		if (pos != r.length()) {
			throw new AssertionError();
		}
		int epsilon[] = transitions[10];
		for (int i = 0; i < 32; i++) {
			epsilon[i] |= 1 << i;
		}
		for (int j = 0; j < 32; j++) {
			for (int i = 0; i < 32; i++) {
				if ((epsilon[i] & (1 << j)) != 0) {
					epsilon[i] |= epsilon[j];
				}
			}
		}
		int start = epsilon[r.length()];
//		System.err.println("Initial state: " + Integer.toBinaryString(start));
		for (int d = 0; d < 10; d++) {
			for (int i = 0; i < 32; i++) {
				for (int j = 0; j < 32; j++) {
					if ((transitions[d][i] & (1 << j)) != 0) {
						transitions[d][i] |= epsilon[j];
					}
				}
			}
		}
		LongLongCounter states = new LongLongCounter();
		states.add(start, 1);
		long ans = 0;
		while (true) {
			while (a < b && a % 10 != 0) {
				ans += getAns(states, a++);
			}
			while (a < b && b % 10 != 0) {
				ans += getAns(states, --b);
			}
			if (a >= b) {
				break;
			}
			LongLongCounter nstates = new LongLongCounter();
			for (LongLongMap.Iterator it = states.iterator(); it.hasNext(); it.advance()) {
				int state = (int) it.getKey();
				long cnt = it.getValue();
				for (int digit = 0; digit < 10; digit++) {
					int nstate = 0;
					for (int i = 0; i < 32; i++) {
						if ((state & (1 << i)) != 0) {
							nstate |= transitions[digit][i];
						}
					}
					nstates.add(nstate, cnt);
				}
			}
			states = nstates;
			a /= 10;
			b /= 10;
		}
		printCase();
		out.println(ans);
		System.err.println("PASS " + test);
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}