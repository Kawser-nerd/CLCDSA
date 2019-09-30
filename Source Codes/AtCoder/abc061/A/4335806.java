import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		System.out.println(c >= a && c <= b ? "Yes" : "No");
	}
}