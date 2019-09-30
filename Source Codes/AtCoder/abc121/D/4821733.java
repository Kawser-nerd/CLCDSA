import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			long a = scanner.nextLong();
			long b = scanner.nextLong();
			scanner.nextLine();
			System.out.println(result(a - 1) ^ result(b));
		}
	}

	private static long result(long input) {
		long remainder = input % 4L;
		switch ((int) remainder) {
		case 0:
			return input;
		case 1:
			return 1L;
		case 2:
			return input + 1;
		case 3:
		default:
			return 0L;
		}
	}
}