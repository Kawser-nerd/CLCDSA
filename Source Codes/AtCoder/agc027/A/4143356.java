import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long x = sc.nextLong();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextLong();
		}
		Arrays.sort(arr);
		long sum = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum <= x) {
				count++;
			}
			if (sum >= x) {
				break;
			}
		}
		if (sum < x) {
			count--;
		}
		System.out.println(count);
	}
}