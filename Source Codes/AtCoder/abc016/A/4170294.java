import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int m = sc.nextInt(), d = sc.nextInt();
		System.out.println(m % d == 0 ? "YES" : "NO");
	}
}