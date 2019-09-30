import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		scanner.close();

		int roundTrip = n / 2;
		if (n % 2 != 0) {
			roundTrip += 1;
		}

		System.out.println(roundTrip);
	}

}