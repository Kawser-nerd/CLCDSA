import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), k = sc.nextInt();
		System.out.println(k * (int) Math.pow(k - 1, n - 1));
	}
}