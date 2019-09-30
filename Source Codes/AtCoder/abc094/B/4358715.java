import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int l = 0;
		int r = 0;
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			if (a < x) {
				l++;
			}
			if (x < a) {
				r++;
			}
		}

		System.out.println(Math.min(l, r));

		sc.close();
	}
}