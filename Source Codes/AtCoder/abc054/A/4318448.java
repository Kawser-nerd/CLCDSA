import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt();
		if (a == b) {
			System.out.println("Draw");
			return;
		}
		if (a == 1) {
			a += 13;
		}
		if (b == 1) {
			b += 13;
		}
		System.out.println(a > b ? "Alice" : "Bob");
	}
}