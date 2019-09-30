import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int count = scanner.nextInt();
			scanner.nextLine();
			System.out.println(IntStream.range(0, count).map(i -> devide2Count(scanner.nextInt())).min().getAsInt());
		}
	}

	/**
	 * number???2??????????
	 * 
	 * @param number
	 * @return
	 */
	private static int devide2Count(int number) {
		int result = 0;
		while (number % 2 == 0) {
			number = number / 2;
			result++;
		}
		return result;
	}
}