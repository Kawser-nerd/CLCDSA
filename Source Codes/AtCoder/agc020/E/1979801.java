import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

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

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static final LongLongMap cache = new LongLongMap();

	static long solve(long lo, long hi, int len) {
		long key;
		if (len < 64) {
			key = (lo | (1L << len)) * 0x80bb3ebe36ea6af5L;
			key = (key << 32) | (key >>> 32);
			key *= 0xf54f6e9bfb097471L;
			key ^= 0xaebb76314b29b919L;
		} else {
			long k1 = lo * 0x0dad7dd20ad4f8dfL;
			k1 = (k1 << 32) | (k1 >>> 32);
			k1 *= 0xbc094dd39a73a2c5L;
			long k2 = (hi | (1L << len)) * 0x1c6b3a03fbf03fa9L;
			k2 = (k2 << 32) | (k2 >>> 32);
			k2 *= 0x6fab831da41df987L;
			key = k1 ^ k2 ^ 0x0208797792b5b79aL;
		}
		long res = cache.get(key, -1);
		if (res == -1) {
			int nAtom, nAll;
			if (len == 1) {
				nAtom = nAll = lo == 0 ? 1 : 2;
			} else {
				nAtom = nAll = 0;
				for (int i = 1; i < len; i++) {
					if (len % i == 0) {
						// i < 64
						long cset = lo;
						for (int j = i; j < len; j += i) {
							int nj = j + i;
							cset &= nj <= 64 ? lo >> j : j < 64 ? (lo >>> j) | (hi << -j) : hi >> j;
						}
						int add = (int) solve(cset & ((1L << i) - 1), 0, i);
						nAtom = add(nAtom, add);
					}
					long lo1, hi1, lo2, hi2;
					if (i < 64) {
						lo1 = lo & ((1L << i) - 1);
						hi1 = 0;
						lo2 = (lo >>> i) | (hi << -i);
						hi2 = hi >>> i;
					} else {
						lo1 = lo;
						hi1 = hi & ((1L << i) - 1);
						lo2 = hi >>> i;
						hi2 = 0;
					}
					int add = mul((int) (solve(lo1, hi1, i) >> 32), (int) solve(lo2, hi2, len - i));
					nAll = add(nAll, add);
				}
				nAll = add(nAll, nAtom);
			}
			res = ((long) nAtom << 32) | (nAll & 0xffffffffL);
//			for (int i = 0; i < len; i++) {
//				System.err.print((((i < 64 ? lo : hi) >> i) & 1) != 0 ? '1' : '0');
//			}
//			System.err.println(" " + nAtom + " " + nAll);
			cache.set(key, res);
		}
		return res;
	}

	static void solve() throws Exception {
		String s = scanString();
		long lo = 0, hi = 0;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s.charAt(i) != '0') {
				if (i < 64) {
					lo |= 1L << i;
				} else {
					hi |= 1L << i;
				}
			}
		}
		out.print((int) solve(lo, hi, len));
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}