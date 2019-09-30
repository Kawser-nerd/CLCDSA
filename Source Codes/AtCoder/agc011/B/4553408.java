import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		long total = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			long a = arr[i];
			if (a > 2 * total) {
				count = 1;
			} else {
				count++;
			}
			total += a;
		}
		System.out.println(count);
	}
}