import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		int count = 0;
		boolean cut = true;
		int inc = 0;
		out: for (int i = 0; i < n; i++) {
			if (cut) {
				if (i == n - 1 || i == n - 2) {
					count++;
					break;
				}
				if (a[i + 1] - a[i] > 0) {
					inc = 1;
					cut = false;
				} else if (a[i + 1] - a[i] < 0){
					inc = -1;
					cut = false;
				} else {
					inc = 0;
				}
			} else {
				switch (inc) {
					case 1:
						if (a[i + 1] - a[i] < 0) {
							count++;
							cut = true;
						} else if (i == n - 2) {
							count++;
							break out;
						}
						break;
					case -1:
						if (a[i + 1] - a[i] > 0) {
							count++;
							cut = true;
						} else if (i == n - 2) {
							count++;
							break out;
						}
						break;
					default:
						if (i == n - 2) {
							count++;
							break out;
						}
						break;
				}
			}
		}
		System.out.println(count);
 	}
}