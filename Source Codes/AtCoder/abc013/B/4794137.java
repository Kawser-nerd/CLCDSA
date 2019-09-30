import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		scanner.close();

		int toPlus = 0;
		int nowP = a;
		while (true) {
			if (getFirstPlace(nowP) == b) {
				break;
			} else {
				toPlus++;
				nowP++;
			}
		}
		int toMinus = Math.abs(10 - toPlus);

		int leastPush = Math.min(toPlus, toMinus);

		System.out.println(leastPush);
	}

	private static int getFirstPlace(int num) {
		int firstPlace = Math.abs(num);
		if (firstPlace >= 10) {
			firstPlace -= 10;
		}

		return firstPlace;
	}

}