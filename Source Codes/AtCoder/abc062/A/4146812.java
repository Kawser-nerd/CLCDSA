import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();

		System.out.println(isSameGroup(x, y));

		sc.close();
	}

	static String isSameGroup(int x, int y) {
		if (x == 2 || y == 2) {
			return "No";
		}

		if ((x % 2 == 1 && x <= 7) || (x % 2 == 0 && x >= 8)) {
			if ((y % 2 == 1 && y <= 7) || (y % 2 == 0 && y >= 8)) {
				return "Yes";
			} else {
				return "No";
			}
		} else if (y == 6 || y == 9 || y == 11) {
			return "Yes";
		} else {
			return "No";
		}
	}

}