import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] l = new int[q];
		int[] r = new int[q];
		int[] a = new int[n];
		for (int i = 0; i < q; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
			a[l[i] - 1]++;
			if (r[i] < n) {
				a[r[i]]--;
			}
		}
		int[] sum = new int[n];
		sum[0] = a[0];
		for (int i = 1; i < n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 0; i < n; i++) {
			if (sum[i] % 2 == 0) {
				System.out.print("0");
			} else {
				System.out.print("1");
			}
		}
		System.out.println();
	}
}