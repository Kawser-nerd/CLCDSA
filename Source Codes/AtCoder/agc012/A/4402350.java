import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[3 * n];
		for (int i = 0; i < 3 * n; i++) {
			a[i] = sc.nextLong();
		}
		Arrays.sort(a);
		long sum = 0;
		int count = 0;
		for (int i = 3 * n - 2; count < n; i -= 2) {
			sum += a[i];
			count++;
		}
		System.out.println(sum);
 	}
}