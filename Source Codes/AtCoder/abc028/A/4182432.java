import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		if (n < 60) {
			System.out.println("Bad");
		} else if (n < 90) {
			System.out.println("Good");
		} else if (n < 100) {
			System.out.println("Great");
		} else {
			System.out.println("Perfect");
		}
	}
}