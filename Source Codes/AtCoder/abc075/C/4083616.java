import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] count = new int[n + 1];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			count[a[i]]++;
			count[b[i]]++;
		}
		int ans = 0;
		boolean bre = true;
		while (bre) {
			bre = false;
			out: for (int i = 0; i <= n; i++) {
				if (count[i] == 1) {
					count[i]--;
					ans++;
					for (int j = 0; j < m; j++) {
						if (a[j] == i) {
							count[b[j]]--;
							a[j] = 0;
							b[j] = 0;
							bre = true;
							break out;
						} else if (b[j] == i) {
							count[a[j]]--;
							a[j] = 0;
							b[j] = 0;
							bre = true;
							break out;
						}
					}
				}
			}
		}
		System.out.println(ans);

	}
}