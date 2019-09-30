import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		long count = 0;
		long cnt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				cnt++;
			} else {
				if (cnt == 1) {
					count++;
				} else {
					count += cnt * (cnt - 1) / 2 + cnt;
				}
				cnt = 1;
			}
		}
		if (cnt == 1) {
			count++;
		} else {
			count += cnt * (cnt - 1) / 2 + cnt;
		}
		System.out.println(count);
	}
}