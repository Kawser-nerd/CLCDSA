import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		System.out.println("" + s.charAt(0) + (s.length() - 2) + s.charAt(s.length() - 1));
	}
}