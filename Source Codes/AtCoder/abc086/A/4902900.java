import java.util.Scanner;

public class Main {

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);
		String[] line = sc.nextLine().split(" ");
		sc.close();

		int a = Integer.parseInt(line[0]);
		int b = Integer.parseInt(line[1]);

		if(isValid(a) && isValid(b)) {
			if (isEven(a, b)) {
				System.out.println("Even");
			} else {
				System.out.println("Odd");
			}
		}
	}

	private static boolean isEven(int a, int b) {

		if ((a * b) % 2 == 0) {
			return true;
		} else {
			return false;
		}
	}

	private static boolean isValid(int num) {
		if (num >= 1 && num <= 10000) {
			return true;
		} else {
			return false;
		}
	}

}