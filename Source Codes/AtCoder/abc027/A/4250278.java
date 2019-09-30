import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		if (a == b) {
			System.out.println(c);
		} else if (a == c) {
			System.out.println(b);
		} else if (b == c) {
			System.out.println(a);
		}
	}
}