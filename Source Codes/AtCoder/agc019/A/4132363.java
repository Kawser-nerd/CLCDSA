import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long q = sc.nextInt();
		long h = sc.nextInt();
		long s = sc.nextInt();
		long d = sc.nextInt();
		long n = sc.nextInt();
		long ans = 0;
		if (q * 2 < h) {
			if (q * 4 < s) {
				if (q * 8 < d) {
					ans = n * 4 * q;
				} else {
					if (n % 2 == 0) {
						ans = n / 2 * d;
					} else {
						ans = n / 2 * d + 4 * q;
					}
				}
			} else {
				if (s * 2 < d) {
					ans = n * s;
				} else {
					if (n % 2 == 0) {
						ans = n / 2 * d;
					} else {
						ans = n / 2 * d + s;
					}
				}
			}
		} else {
			if (h * 2 < s) {
				if (h * 4 < d) {
					ans = n * 2 * h;
				} else {
					if (n % 2 == 0) {
						ans = n / 2 * d;
					} else {
						ans = n / 2 * d + 2 * h;
					}
				}
			} else {
				if (s * 2 < d) {
					ans = n * s;
				} else {
					if (n % 2 == 0) {
						ans = n / 2 * d;
					} else {
						ans = n / 2 * d + s;
					}
				}
			}
		}
		System.out.print(ans);
	}
			
}