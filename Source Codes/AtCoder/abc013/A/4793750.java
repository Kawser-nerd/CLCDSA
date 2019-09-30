import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String x = scanner.nextLine();
		scanner.close();

		String[] alphabets = {"A", "B", "C", "D", "E"};
		int order = Arrays.asList(alphabets).indexOf(x) + 1;

		System.out.println(order);
	}

}