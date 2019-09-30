import java.util.*;

public class Main {
	public static long MOD = 1000000007l;

	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] a = new String[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		sc.close();
		char first = a[0].charAt(a[0].length() - 1);
		boolean ans = true;
		for (int i = 1; i < n; i++) {
			if (!(first == a[i].charAt(0))) {
				ans = false;
				break;
			} else {
				// System.out.println(first);
				first = a[i].charAt(a[i].length() - 1);
				// System.out.println(first);
			}
		}
		if (ans) {
			Arrays.sort(a);
			String prev = a[0];
			for (int i = 1; i < n; i++) {
				if (prev.equals(a[i])) {
					ans = false;
					break;
				} else {
					prev = a[i];
				}
			}
		}
		System.out.println(ans ? "Yes" : "No");
	}
}