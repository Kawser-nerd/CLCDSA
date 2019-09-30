import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String nx = scanner.nextLine();
		String price = scanner.nextLine();
		scanner.close();

		int n = Integer.parseInt(nx.split(" ")[0]);
		int x = Integer.parseInt(nx.split(" ")[1]);
		String[] prices = price.split(" ");

		String bitX = Integer.toBinaryString(x);
		int toAddZero = n - bitX.length();
		for (int i = 0; i < toAddZero; i++) {
			bitX = "0" + bitX;
		}

		boolean[] shouldAdd = new boolean[n];
		for (int i = 0; i < n; i++) {
			String bit = bitX.substring(bitX.length() - 1 - i, bitX.length() - i);
			shouldAdd[i] = bit.equals("1");
		}

		int sumPrice = 0;
		for (int i = 0; i < shouldAdd.length; i++) {
			if (shouldAdd[i]) {
				sumPrice += Integer.parseInt(prices[i]);
			}
		}

		System.out.println(sumPrice);
	}

}