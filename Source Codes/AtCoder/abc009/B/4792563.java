import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		ArrayList<Integer> prices = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int price = scanner.nextInt();
			if (!prices.contains(price)) {
				prices.add(price);
			}
		}
		scanner.close();

		int first = 0, second = 0;
		for (int price : prices) {
			if (price > first) {
				second = first;
				first = price;
			} else if (price > second) {
				second = price;
			}
		}

		System.out.println(second);
	}

}