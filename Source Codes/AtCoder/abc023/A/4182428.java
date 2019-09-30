import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		System.out.println(Integer.parseInt(s.charAt(0) + "") + Integer.parseInt(s.charAt(1) + ""));
	}
}