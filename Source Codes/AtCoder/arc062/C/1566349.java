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
		long a = rand.nextInt((int) p - 1) + 1;
		long b = rand.nextInt((int) p - 1) + 1;
		int sz = 16;
		int cnt = 0;
		LinkedList<Pair>[] list;

		public HashMap() {
			list = new LinkedList[sz];
			for (int i = 0; i < list.length; ++i) {
				list[i] = new LinkedList<>();
			}
		}

		public HashMap(int sz_) {
			sz = sz_;
			list = new LinkedList[sz];
			for (int i = 0; i < list.length; ++i) {
				list[i] = new LinkedList<>();
			}
		}

		boolean delete(long key) {
			int id = hash(key);
			boolean ret = list[id].remove(key);
			if (sz >= 3 * cnt) {
				changeSize(sz / 2);
			}
			return ret;
		}

		void put(long key, long value) {
			int id = hash(key);
			for (int i = 0; i < list[id].size(); ++i) {
				if (list[id].get(i).key == key) {
					list[id].get(i).value = value;
					return;
				}
			}
			list[id].add(new Pair(key, value));
			++cnt;

			if (cnt > sz) {
				changeSize(2 * sz);
			}

			return;
		}

		long get(long key) {
			int id = hash(key);
			for (int i = 0; i < list[id].size(); ++i) {
				if (list[id].get(i).key == key) {
					return list[id].get(i).value;
				}
			}
			throw new AssertionError();
		}

		boolean containsKey(long key) {
			int id = hash(key);
			for (int i = 0; i < list[id].size(); ++i) {
				if (list[id].get(i).key != key) {
					continue;
				}
				return true;
			}
			return false;
		}

		int hash(long v) {
			return (int) ((a * v % p + b) % p % sz);
		}

		void changeSize(int sz_) {
			LinkedList<Pair>[] tmp = new LinkedList[sz];
			for (int i = 0; i < tmp.length; ++i) {
				tmp[i] = new LinkedList<>();
				tmp[i].addAll(list[i]);
			}
			sz = sz_;
			list = new LinkedList[sz];
			for (int i = 0; i < list.length; ++i) {
				list[i] = new LinkedList<>();
			}
			for (int i = 0; i < tmp.length; ++i) {
				for (Pair p : tmp[i]) {
					put(p.key, p.value);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.