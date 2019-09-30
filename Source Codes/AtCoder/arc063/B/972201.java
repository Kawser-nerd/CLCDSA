import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int T = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		A[0] = Integer.MAX_VALUE;

		int max = 0;
		int last_min_i = N;
		int max_start_i = N;
		int diff_max = 0;
		int cost = 0;
		for (int i = N; i >= 0; i--) {
			if (A[i] > max) {
				if (diff_max > 0) {
					int cost0 = 0;
					int cost1 = 0;
					for (int j = i + 1; j <= max_start_i; j++) {
						if (A[j] == max && j >= last_min_i) {
							cost0++;
						} else if (A[j] == max - diff_max) {
							if (cost0 > cost1) {
								cost0 = cost1;
							}
							cost1++;
						}
					}
					cost += Math.min(cost0, cost1);
				}
				max = A[i];
				max_start_i = i;
			} else if (A[i] == max) {
				//
			} else {
				if (max - A[i] == diff_max) {
					last_min_i = i;
				} else if (max - A[i] > diff_max) {
					diff_max = max - A[i];
					last_min_i = i;
					cost = 0;
				}
			}
		}

		System.out.println(cost);
	}
}