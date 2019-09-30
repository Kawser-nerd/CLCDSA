import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		if (n == 0 || n == 1111 | n == 2222 || n == 3333 || n == 4444
			|| n == 5555 || n == 6666 || n == 7777 || n == 8888 || n == 9999) {
			System.out.println("SAME");
		} else {
			System.out.println("DIFFERENT");
		}
	}
}