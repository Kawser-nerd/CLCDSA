import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = Integer.parseInt(scanner.nextLine());
		String h = scanner.nextLine();
		scanner.close();

		String[] flowers = new String[n];
		flowers = h.split(" ");

		int toPluck = 0;
		for (String flower : flowers) {
			int num = Integer.parseInt(flower);
			int minus = 0;
			while (shouldPluck(num - minus)) {
				toPluck++;
				minus++;
			}
		}

		System.out.println(toPluck);
	}

	private static boolean shouldPluck(int num) {
		boolean shouldPluck = false;

		if (num % 3 == 2 || num % 2 == 0) {
			shouldPluck = true;
		}

		return shouldPluck;
	}

}