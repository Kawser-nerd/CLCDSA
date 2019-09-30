import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		String s = sc.next();
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		for (int i = 0; i < s.length(); ++i) {
			dq.add(s.charAt(i) == 'A' ? 1 : -1);
		}
		int cur = 1;
		long res = 0;
		HashMap<String, Integer> map = new HashMap<>();
		HashMap<Integer, String> map2 = new HashMap<>();
		int id = 0;
		for (long i = 0; i < K; ++i) {
			int v = dq.pollFirst();
			if (v * cur == 1) {
				dq.addFirst(cur * (-1));
			} else {
				cur *= -1;
				dq.addLast(cur);
			}
			if (i > 2 * N) {
				res = K - i - 1;
				String str = getans(dq, cur);
				if (map.containsKey(str)) {
					int ansid = (int) res % id;
					String ans = map2.get(ansid);
					System.out.println(ans);
					return;
				} else {
					map.put(str, id);
					map2.put(id, str);
					++id;
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		while (!dq.isEmpty()) {
			sb.append(dq.pollFirst() * cur == 1 ? 'A' : 'B');
		}
		System.out.println(sb);
	}

	String getans(ArrayDeque<Integer> dq, int cur) {
		StringBuilder sb = new StringBuilder();
		ArrayDeque<Integer> tmp = new ArrayDeque<>();
		tmp.addAll(dq);
		while (!tmp.isEmpty()) {
			sb.append(tmp.pollFirst() * cur == 1 ? 'A' : 'B');
		}
		return sb.toString();

	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}