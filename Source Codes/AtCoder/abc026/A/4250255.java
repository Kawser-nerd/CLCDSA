import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt();
		if (a % 2 == 0) {
			System.out.println(a / 2 * a / 2);
		} else {
			System.out.println(a / 2 * (a / 2 + 1));
		}
	}
}