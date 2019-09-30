import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		int[] cnt = new int[N];
		int min = N + 1;
		int max = 0;
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			cnt[a[i]] += 1;
			min = Math.min(min, a[i]);
			max = Math.max(max, a[i]);
		}
		sc.close();

		String POSSIBLE = "Possible";
		String IMPOSSIBLE = "Impossible";
		String ans = POSSIBLE;
		if (cnt[min] == 1) {
			if (max == min * 2) {
				ans = POSSIBLE;
				for (int i = min + 1; i <= max; i++) {
					if (cnt[i] < 2) {
						ans = IMPOSSIBLE;
						break;
					}
				}
			} else {
				ans = IMPOSSIBLE;
			}
		} else if (cnt[min] == 2) {
			if (max == min * 2 - 1) {
				ans = POSSIBLE;
				for (int i = min + 1; i <= max; i++) {
					if (cnt[i] < 2) {
						ans = IMPOSSIBLE;
						break;
					}
				}
			} else {
				ans = IMPOSSIBLE;
			}
		} else {
			ans = IMPOSSIBLE;
		}

		System.out.println(ans);
	}
}