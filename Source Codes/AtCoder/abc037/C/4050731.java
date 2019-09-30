import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[] arr = new long[n];
		long total = 0;
		long prev = 0;
		for (int i = 0; i < n; i++) {
			long a = sc.nextLong();
			arr[i] = a;
			prev += a;
			if (i >= k - 1) {
				total += prev;
				prev -= arr[i - (k - 1)];
			}
		}
		System.out.print(total);
	}
}