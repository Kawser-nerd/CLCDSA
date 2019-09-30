import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		long[] b = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
			b[i] = sc.nextLong();
		}
		long add = 0;
		for (int i = n - 1; i >= 0; i--) {
			if ((a[i] + add) % b[i] == 0) {

			} else if (b[i] >= a[i] + add) {
				add += b[i] - (a[i] + add);
			} else {
				long bai = (a[i] + add) / b[i] + 1;
				add += b[i] * bai - (a[i] + add);
			}
		}
		System.out.println(add);
	}
}