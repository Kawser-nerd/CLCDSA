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
		int max = -50000;
		for (int i = 0; i < n; i++) {
			int maxtaka = -50000;
			int maxaoki = -50000;
			for (int j = 0; j < n; j++) {
				int taka = 0;
				int aoki = 0;
				if (i == j) {
					continue;
				} else if (i < j) {
					for (int k = i; k <= j; k++) {
						if ((k - i + 1) % 2 == 0) {
							aoki += a[k];
						} else {
							taka += a[k];
						}
					}
				} else if (i > j) {
					for (int k = j; k <= i; k++) {
						if ((k - j + 1) % 2 == 0) {
							aoki += a[k];
						} else {
							taka += a[k];
						}
					}
				}
				if (aoki > maxaoki) {
					maxtaka = taka;
					maxaoki = aoki;
				}
			}
			max = Math.max(max, maxtaka);
		}
		System.out.println(max);
	}
}