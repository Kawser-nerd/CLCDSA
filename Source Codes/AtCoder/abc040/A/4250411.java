import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), x = sc.nextInt();
		if (n / 2 < x) {
			System.out.println(n - x);
		} else {
			System.out.println(x - 1);
		}
	}
}