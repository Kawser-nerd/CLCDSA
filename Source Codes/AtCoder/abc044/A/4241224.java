import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), k = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
		System.out.println(Math.min(n, k) * x + Math.max(n - k, 0) * y);
	}
}