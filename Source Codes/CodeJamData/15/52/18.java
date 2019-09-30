package round3;

import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			int N = sc.nextInt();
			int K = sc.nextInt();
			int[] sums = new int[N-K+1];
			for (int i = 0; i < sums.length; i++) {
				sums[i] = sc.nextInt();
			}
			int[] min = new int[K], max = new int[K];
			for (int i = 0; i < K; i++) {
				int val = 0;
				for (int j = i; j + 1 < sums.length; j+=K) {
					val += sums[j+1] - sums[j];
					min[i] = Math.min(min[i], val);
					max[i] = Math.max(max[i], val);
				}
			}
			int sumModulo = 0, maxInterval = 0, canUse = 0;
			for (int i = 0; i < K; i++) {
				sumModulo -= min[i];
				maxInterval = Math.max(maxInterval, max[i]-min[i]);
			}
			for (int i = 0; i < K; i++) {
				canUse += maxInterval - (max[i]-min[i]);
			}
			boolean can = false;
			for (int i = 0; i <= canUse; i++) {
				if ((sumModulo + i - sums[0]) % K == 0) {
					can = true;
					break;
				}
			}
			if (!can) maxInterval++;

			System.out.println("Case #" + caze + ": " + maxInterval);
		}
	}

}
