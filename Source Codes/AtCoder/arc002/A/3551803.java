import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		// ???????
		int year = sc.nextInt();

		boolean LY = false;

		if (year % 4 == 0) {
			LY = true;
		}

		if (year % 100 == 0) {
			LY = false;
		}

		if (year % 400 == 0) {
			LY = true;
		}

		if (LY) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

	}

}