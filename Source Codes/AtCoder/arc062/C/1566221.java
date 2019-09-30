import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main implements Runnable {

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
		HashMap<Long, Integer> map = new HashMap<>();
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
					HashMap<Long, Integer> pending = new HashMap<>();
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