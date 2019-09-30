import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[] a = new long[n];
		long[] sum = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		sum[0] = a[0];
		for (int i = 1; i < n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		long su = sum[k - 1];
		for (int i = k; i < n; i++) {
			su += sum[i] - sum[i - k];
		}
		System.out.println(su);
	}
}