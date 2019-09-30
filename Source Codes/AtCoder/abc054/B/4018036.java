import java.util.*;
import java.lang.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for (int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		for (int i = 0; i < m; i++) {
			b[i] = sc.next();
		}
		boolean pos = false;
		out: for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				boolean bre = false;
				for (int k = 0; k < m; k++) {
					if (!b[k].equals(a[i + k].substring(j, j + m))) {
						bre = true;
						break;
					}
				}
				if (!bre) {
					pos = true;
					break out;
				}
			}
		}
		if (pos) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}