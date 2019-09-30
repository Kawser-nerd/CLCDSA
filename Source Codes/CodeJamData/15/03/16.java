import java.util.Scanner;

public class C {
	static Scanner sc = new Scanner(System.in);
	static int[][] table = new int[8][8];

	public static void main(String[] args) {
		table[0] = new int[] { 0, 1, 2, 3, 4, 5, 6, 7 };
		table[1] = new int[] { 1, 4, 3, 6, 5, 0, 7, 2 };
		table[2] = new int[] { 2, 7, 4, 1, 6, 3, 0, 5 };
		table[3] = new int[] { 3, 2, 5, 4, 7, 6, 1, 0 };
		for (int i = 4; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				table[i][j] = table[i - 4][j] + 4;
				if (table[i][j] >= 8) table[i][j] -= 8;
			}
		}
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
		}
	}

	static boolean solve() {
		int L = sc.nextInt();
		long X = sc.nextLong();
		String str = sc.next();
		int[] ch = new int[L];
		for (int i = 0; i < L; ++i) {
			ch[i] = "1ijk".indexOf(str.charAt(i));
		}
		int cur = 0;
		int target = 1;
		for (int i = 0; i < Math.min(1000, X); ++i) {
			for (int j = 0; j < L; ++j) {
				cur = table[cur][ch[j]];
				if (cur == target) {
					target = (target == 1 ? 2 : 99);
					cur = 0;
				}
			}
			if (target == 99) {
				int one = 0;
				for (int j = 0; j < L; ++j) {
					one = table[one][ch[j]];
				}
				int rest = table[cur][pow(one, X - i - 1)];
				return rest == 3;
			}
		}

		return false;
	}

	static int pow(int base, long p) {
		if (p == 0) return 0;
		if (p == 1) return base;
		int ret = Math.abs(pow(base, p / 2));
		ret = table[ret][ret];
		if (p % 2 == 1) {
			ret = table[ret][base];
		}
		return ret;
	}

}
