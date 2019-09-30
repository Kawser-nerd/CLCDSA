import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static int[] map = new int[26];

	static class Solver {

		int k;
		boolean[][] used = new boolean[34][34];

		int solve() {
			k = sc.nextInt();
			String S = sc.next();
			for (int i = 0; i < S.length() - 1; ++i) {
				int v1 = S.charAt(i) - 'a';
				int v2 = S.charAt(i + 1) - 'a';
				used[v1][v2] = true;
				if (map[v1] != 0) {
					used[map[v1]][v2] = true;
				}
				if (map[v2] != 0) {
					used[v1][map[v2]] = true;
				}
				if (map[v1] != 0 && map[v2] != 0) {
					used[map[v1]][map[v2]] = true;
				}
			}
			int[] pre = new int[used.length];
			int[] suf = new int[used.length];
			int ans = 0;
			for (int i = 0; i < used.length; ++i) {
				for (int j = 0; j < used.length; ++j) {
					if (!used[i][j]) continue;
					++pre[i];
					++suf[j];
					ans += 2;
				}
			}
			int sub = 0;
			for (int i = 0; i < used.length; ++i) {
				sub += Math.min(pre[i], suf[i]);
			}
			return sub == ans / 2 ? ans / 2 + 1 : ans - sub;
		}
	}

	public static void main(String[] args) {
		map['o' - 'a'] = 26;
		map['i' - 'a'] = 27;
		map['e' - 'a'] = 28;
		map['a' - 'a'] = 29;
		map['s' - 'a'] = 30;
		map['t' - 'a'] = 31;
		map['b' - 'a'] = 32;
		map['g' - 'a'] = 33;
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			Solver solver = new Solver();
			System.out.println(solver.solve());
		}
	}
}
