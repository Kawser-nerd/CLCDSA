import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] arrA = new long[n];
		long[] arrB = new long[n];
		for (int i = 0; i < n; i++) {
			arrA[i] = sc.nextInt();
			arrB[i] = sc.nextInt();
		}
		long count = 0;
		for (int i = n - 1; i >= 0; i--) {
			long mod = (arrA[i] + count) % arrB[i];
			if (mod > 0) {
				count += arrB[i] - mod;
			}
		}
		System.out.println(count);
	}
}