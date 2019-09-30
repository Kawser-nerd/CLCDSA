import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), m = sc.nextInt();
		String[] a = new String[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		String[] b = new String[m];
		for (int i = 0; i < m; i++) {
			b[i] = sc.next();
		}
		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				boolean ans = true;
				for (int k = 0; k < m; k++) {
					for (int l = 0; l < m; l++) {
						if (a[i + k].charAt(j + l) != b[k].charAt(l)) {
							ans = false;
						}
					}
				}
				if (ans) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}