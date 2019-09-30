import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		for (int i = 0; i <= 100 / 4 + 1; i++) {
			for (int j = 0; j <= 100 / 7 + 1; j++) {
				if (i * 4 + j * 7 == n) {
					System.out.println("Yes");
					return;
				}
			}
		}
		System.out.println("No");
	}
}