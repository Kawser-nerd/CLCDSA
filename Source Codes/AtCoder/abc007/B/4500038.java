import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		sc.close();

		String result = solve(input);

		System.out.println(result);
	}

	/**
	 * ????????????????
	 *
	 * @param input ???
	 */
	private static String solve(String input) {

		String firstStr = input.substring(0, 1);

		if (!firstStr.equals("a")) {

			return "a";
		}

		int length = input.length();

		if (length == 1) {

			return "-1";
		}

		return input.substring(0, length - 1);
	}
}