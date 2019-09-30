import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int sum = 0;
		int maxL = 0;
		for (int i = 0; i < n; i++) {
			int l = sc.nextInt();
			sum += l;
			if (l > maxL) {
				maxL = l;
			}
		}

		System.out.println((sum - maxL) > maxL ? "Yes" : "No");

		sc.close();
	}
}