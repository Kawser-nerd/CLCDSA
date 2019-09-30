import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), d = sc.nextInt();
		if (a > d) {
			System.out.println(a * (d + 1));
		} else {
			System.out.println((a + 1) * d);
		}
	}
}