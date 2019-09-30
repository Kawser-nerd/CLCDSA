import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long x = sc.nextInt();
		long[] arr = new long[n];
		long total = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			total += arr[i];
		}
		long[] minArr = (long[])arr.clone();
		long min = total;
		for (int i = 1; i < n; i++) {
			total = 0;
			long w = minArr[n - 1];
			for (int j = n - 1; j > 0; j--) {
				minArr[j] = Math.min(minArr[j - 1], arr[j]);
				total += minArr[j];
			}
			minArr[0] = Math.min(w, arr[0]);
			total += minArr[0];
			total += i * x;
			if (min > total) {
				min = total;
			}
		}
		System.out.println(min);
	}
}