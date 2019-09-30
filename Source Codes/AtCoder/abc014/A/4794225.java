import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		scanner.close();

		int splited = a / b;
		int toBuy = 0;
		if (a % b != 0) {
			toBuy = (splited + 1) * b - (splited * b + a % b);
		}

		System.out.println(toBuy);
	}

}