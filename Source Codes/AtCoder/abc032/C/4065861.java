import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextLong();
			if (arr[i] == 0) {
				System.out.println(n);
				return;
			}
		}
		long value = 1;
		int start = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			value *= arr[i];
			if (value <= k) {
				int len = i - start + 1;
				if (max < len) {
					max = len;
				}
			} else {
				while (value > k && value != 1) {
					value /= arr[start];
					start++;
				}
			}
		}
		System.out.println(max);
	}
}