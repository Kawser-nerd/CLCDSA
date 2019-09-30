import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		int next = n + 1;
		if (n == 12) {
			next = 1;
		}

		System.out.println(next);
	}

}