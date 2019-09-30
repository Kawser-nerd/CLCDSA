import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class Main implements Runnable {
	class HashMap {
		class Pair {
			long key;
			long value;

			public Pair(long key_, long value_) {
				key = key_;
				value = value_;
			}
		}

		Random rand = new Random();
		long p = (long) 1e6 + 7;
		long a1 = rand.nextInt((int) p - 1) + 1;
		long b1 = rand.nextInt((int) p - 1) + 1;
		long a2 = rand.nextInt((int) p - 1) + 1;
		long b2 = rand.nextInt((int) p - 1) + 1;
		int sz = 16;
		int cnt = 0;
		Pair[] array;
		int[] flag;// 0 : unused,1:used,2:deleted

		public HashMap() {
			array = new Pair[sz];
			flag = new int[sz];
		}

		public HashMap(int sz_) {
			sz = sz_;
			array = new Pair[sz];
		}

		long get(long key) {
			int id = -1;
			for (int i = 0; i < sz; ++i) {
				id = id(key, i);
				if (flag[id] == 1 && array[id].key == key) {
					return array[id].value;
				}
				if (flag[id] == 0) {
					throw new AssertionError();
				}
				if (flag[id] == 1 || flag[id] == 2) {
					continue;
				}
			}
			throw new AssertionError();
		}

		boolean containsKey(long key) {
			int id = -1;
			for (int i = 0; i < sz; ++i) {
				id = id(key, i);
				if (flag[id] == 0)
					return false;
				if (flag[id] == 2)
					continue;
				if (array[id].key == key) {
					return true;
				}
			}
			return false;
		}

		boolean delete(long key) {
			int id = -1;
			for (int i = 0; i < sz; ++i) {
				id = id(key, i);
				if (flag[id] == 1 && array[id].key == key) {
					array[id] = null;
					flag[id] = 2;
					if (sz >= 8 * cnt) {
						changeSize(sz / 2);
					}
					return true;
				}
				if (flag[id] == 0) {
					return false;
				}
				if (flag[id] == 1 || flag[id] == 2) {
					continue;
				}
			}
			return false;

		}

		boolean put(long key, long value) {

			int id = -1;
			for (int i = 0; i < sz; ++i) {
				id = id(key, i);
				if (flag[id] == 1) {
					if (array[id].key == key) {
						array[id].value = value;
						return true;
					}
				}
				if (flag[id] == 0 || flag[id] == 2) {
					array[id] = new Pair(key, value);
					flag[id] = 1;
					++cnt;
					if (2 * cnt == sz) {
						changeSize(2 * sz);
					}
					return true;
				}
			}
			throw new AssertionError();
		}

		int hash1(long v) {
			return (int) ((a1 * v % p + b1) % p % sz);
		}

		int hash2(long v) {
			return (int) ((a2 * v % p + b2) % p % sz);
		}

		int id(long v, int i) {
			return (hash1(v) + i * (2 * hash2(v) + 1)) % sz;
		}

		void changeSize(int sz_) {
			Pair[] tmp = new Pair[sz];
			int[] tmpFlag = new int[sz];
			for (int i = 0; i < array.length; ++i) {
				tmp[i] = array[i];
				tmpFlag[i] = flag[i];
			}
			sz = sz_;
			array = new Pair[sz];
			flag = new int[sz];
			cnt = 0;
			for (int i = 0; i < tmp.length; ++i) {
				if (tmpFlag[i] == 1) {
					put(tmp[i].key, tmp[i].value);
				}
			}
		}
	}

	long hash(int[] cs) {
		long ret = Long.MAX_VALUE;
		for (int i = 0; i < cs.length; ++i) {
			long hash = 0;
			for (int j = 0; j < cs.length; ++j) {
				hash = hash * 1000 + cs[(i + j) % cs.length];
			}
			ret = Math.min(ret, hash);
		}
		return ret;
	}

	long rot(int[] cs) {
		int cnt = 0;
		long originHash = hash(cs);
		for (int i = 0; i < cs.length; ++i) {
			long hash = 0;
			for (int j = 0; j < cs.length; ++j) {
				hash = hash * 1000 + cs[(i + j) % cs.length];
			}
			if (hash == originHash) {
				++cnt;
			}
		}
		return cnt;
	}

	void solver(int n, int[][] C) {
		// HashMap<Long, Integer> map = new HashMap<>();
		HashMap map = new HashMap();
		for (int i = 0; i < n; ++i) {
			if (map.containsKey(hash(C[i]))) {
				map.put(hash(C[i]), map.get(hash(C[i])) + 1);
			} else {
				map.put(hash(C[i]), 1);
			}
		}

		long ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				loop: for (int rotation = 0; rotation < 4; ++rotation) {
					long sum = 1;
					// HashMap<Long, Integer> pending = new HashMap<>();
					HashMap pending = new HashMap();
					pending.put(hash(C[i]), 1);
					pending.put(hash(C[j]), hash(C[i]) == hash(C[j]) ? 2 : 1);

					for (int k = 0; k < 4; ++k) {
						int[] nc = { C[j][(-k + 1 + rotation + 4) % 4], C[j][(-k + rotation + 4) % 4],
								C[i][(k + 1) % 4], C[i][k] };
						if (!map.containsKey(hash(nc))) {
							continue loop;
						}
						if (pending.containsKey(hash(nc)) && map.get(hash(nc)) == pending.get(hash(nc)))
							continue loop;
						sum *= (map.get(hash(nc)) - (!pending.containsKey(hash(nc)) ? 0 : pending.get(hash(nc))))
								* rot(nc);
						if (pending.containsKey(hash(nc))) {
							pending.put(hash(nc), pending.get(hash(nc)) + 1);
						} else {
							pending.put(hash(nc), 1);
						}
					}
					ans += sum;
				}
			}
		}
		System.out.println(ans / 6);
	}

	void start() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] C = new int[n][4];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 4; ++j) {
				C[i][j] = sc.nextInt();
			}
		}
		solver(n, C);
	}

	public void run() {
		start();
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}