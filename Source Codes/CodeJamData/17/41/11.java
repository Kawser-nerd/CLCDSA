package round2;

import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt();
			int P = sc.nextInt();
			int[] cant = new int[P];
			for (int i = 0; i < N; i++) {
				cant[sc.nextInt() % P]++;
			}
			int ans = cant[0];
			if (P == 2) {
				ans += (cant[1] +1) / 2;
			} else if (P == 3) {
				ans += Math.min(cant[1], cant[2]);
				int left = Math.max(cant[1], cant[2]) - Math.min(cant[1], cant[2]);
				ans += (left + 2) / 3;
			} else {
				ans += Math.min(cant[1], cant[3]);
				int left = Math.max(cant[1], cant[3]) - Math.min(cant[1], cant[3]);
				ans += cant[2] / 2;
				boolean extra2 = cant[2] % 2 == 1;
				if (left >= 2 && extra2) {
					ans++;
					left -= 2;
					extra2 = false;
				}
				if (extra2) left++;
				ans += (left + 3) / 4;
			}
			System.out.println("Case #" + caze + ": " + ans);
		}
	}
}
