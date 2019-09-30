import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt();
		String s = sc.next();
		int b = sc.nextInt();
		System.out.println(s.equals("+") ? a + b : a - b);
	}
}