import java.util.*;

public class Main {
	static final int MOD = 1000000007;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int[] idxes = new int[n];
		Arrays.fill(idxes, -1);
		int idx = 1;
		for (int i = 0; i < n; i++) {
			while (arr[idx] < arr[i] * 2) {
				idx++;
				if (idx >= n) {
					break;
				}
			}
			if (idx >= n) {
				break;
			}
			idxes[i] = idx;
		}
		int[] third = new int[n];
		for (int i = 1; i < n - 2; i++) {
			if (idxes[n - 1 - i] != -1) {
				third[n - 1 - i] = (third[n - i] + n - idxes[n - 1 - i]) % MOD;
			}
		}
		int [] second = new int[n];
		for (int i = 2; i < n - 1; i++) {
			if (idxes[n - 1 - i] != -1) {
				second[n - 1 - i] = (second[n - i] + third[idxes[n - 1 - i]]) % MOD;
			}
		}
		int sum = 0;
		for (int i = 3; i < n; i++) {
			if (idxes[n - 1 - i] != -1) {
				sum += second[idxes[n - 1 - i]];
				sum %= MOD;
			}
		}
		System.out.println(sum);
	}
}