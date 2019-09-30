import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String a = sc.next(), b = sc.next();
		System.out.println(a.equals(b) ? "H" : "D");
	}
}