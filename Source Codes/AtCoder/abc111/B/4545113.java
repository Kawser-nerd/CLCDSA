import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int ans = 999;
		for (int i = n; i < 1000; i++) {
			if (i % 111 == 0) {
				ans = i;
				break;
			}
		}

		System.out.println(ans);
		sc.close();
	}

}