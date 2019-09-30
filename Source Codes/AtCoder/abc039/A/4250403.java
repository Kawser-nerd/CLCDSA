import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		System.out.println(a * b * 2 + a * c * 2 + b * c * 2);
	}
}