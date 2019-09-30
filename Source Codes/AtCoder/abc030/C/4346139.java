import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			b[i] = sc.nextInt();
		}
		int count = 1;
		int now = 1;
		int time = a[0] + x;
		while (true) {
			if (now == 0) {
				if (time > a[n - 1]) {
					break;
				}
				int ng = -1;
				int ok = n - 1;
				while (ok - ng > 1) {
					int mid = (ok + ng) / 2;
					if (a[mid] >= time) {
						ok = mid;
					} else {
						ng = mid;
					}
				}
				now = 1;
				time = a[ok] + x;
				count++;
			} else {
				if (time > b[m - 1]) {
					break;
				}
				int ng = -1;
				int ok = m - 1;
				while (ok - ng > 1) {
					int mid = (ok + ng) / 2;
					if (b[mid] >= time) {
						ok = mid;
					} else {
						ng = mid;
					}
				}
				now = 0;
				time = b[ok] + y;
				count++;
			}
		}
		System.out.println(count / 2);
	}
}