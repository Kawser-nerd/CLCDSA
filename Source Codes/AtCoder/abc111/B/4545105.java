import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int ans = 999;
		for (int i = n; i < 1000; i++) {
			int a = i / 100;
			int b = i / 10 % 10;
			int c = i % 10;
			if (a == b && b == c && c == a) {
				ans = i;
				break;
			}
		}

		System.out.println(ans);
		sc.close();
	}

}