import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int x = sc.nextInt(), y = sc.nextInt();
		System.out.println(x + y >= 10 ? "error" : x + y);
	}
}