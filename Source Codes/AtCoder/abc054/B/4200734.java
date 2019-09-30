import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];

		for (int i = 0; i < a.length; i++) {
			a[i] = sc.next();
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = sc.next();
		}

		for (int i = 0; i <= n - m; i++) {
			outer:
			for (int j = 0; j <= n - m; j++) {
				for (int k = 0; k < m; k++) {
					for (int l = 0; l < m; l++) {
						if (a[i + k].charAt(j + l) != b[k].charAt(l)) {
							continue outer;
						}
					}
				}
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");

		sc.close();
	}
}