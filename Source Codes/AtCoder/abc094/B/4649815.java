import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
		}
		// x???????????
		int lec = 0;
		for (int i = 1; i < x; i++) {
			for (int j = 0; j < m; j++) {
				if (i == a[j]) {
					lec++;
				}
			}
		}
		// x???????????
		int ric = 0;
		for (int i = x + 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == a[j]) {
					ric++;
				}
			}
		}
		System.out.println(Math.min(lec, ric));
	}

}