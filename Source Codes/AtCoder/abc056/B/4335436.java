import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int w = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
		System.out.println(Math.max(Math.max(b - (a + w), a - (b + w)), 0));
	}
}