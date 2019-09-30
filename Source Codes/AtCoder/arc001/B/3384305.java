import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		int ct = 0;
		while (a != b) {
			int c = b - a;
			if (c >= 10) {
				a += 10;
				ct++;
			} else if (c < 10) {
				int d = Math.abs(c - 10);
				if (d <= 2) {
					a += 10;
					ct++;
				} else if (d > 2) {
					int e = Math.abs(c - 5);
					if (e <= 2) {
						a += 5;
						ct++;
					} else if (c < 0) {
						a -= 1;
						ct++;
					} else if (c > 0 && c < 5) {
						a += 1;
						ct++;
					}
				}
			}
		}
		System.out.println(ct);
	}
}