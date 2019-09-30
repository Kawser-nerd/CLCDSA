import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		String msg = "NO";
		if (n == 3 || n % 3 == 0) {
			msg = "YES";
		}

		System.out.println(msg);
	}

}