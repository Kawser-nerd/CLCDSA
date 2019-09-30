import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		double a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
		if (b / a == d / c) {
			System.out.println("DRAW");
		} else if (b / a > d / c) {
			System.out.println("TAKAHASHI");
		} else {
			System.out.println("AOKI");
		}
	}
}