import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String S = sc.next();
		System.out.println(S.substring(0,1).toUpperCase() + S.substring(1).toLowerCase());
	}
}