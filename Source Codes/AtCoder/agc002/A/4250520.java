import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt();
		if (a < 0 && b >= 0 || a == 0) {
			System.out.println("Zero");
		} else if (b < 0 && (b - a) % 2 != 0 || a > 0) {
			System.out.println("Positive");
		} else {
			System.out.println("Negative");
		}
	}
}