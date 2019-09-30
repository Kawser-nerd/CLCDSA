import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int maxA = Integer.MIN_VALUE;
			int idxA = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				int start = i;
				int end = j;
				if (i > j) {
					start = j;
					end = i;
				}

				int sum = 0;
				for (int k = start; k <= end; k++) {
					if ((k - start) % 2 == 1) {
						sum += a[k];
					}
				}
				if (maxA < sum) {
					maxA = sum;
					idxA = j;
				}
			}

			int start = i;
			int end = idxA;
			if (i > idxA) {
				start = idxA;
				end = i;
			}
			int sum = 0;
			for (int k = start; k <= end; k++) {
				if ((k - start) % 2 == 0) {
					sum += a[k];
				}
			}
			ans = Math.max(ans, sum);
		}
		System.out.println(ans);
	}
}