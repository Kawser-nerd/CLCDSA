import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int N = sc.nextInt();
		int k = 0;
		if (N == 0) {
			System.out.println(0);
		} else if (N == 1) {
			System.out.println(1);

		} else if (N > 1 && N <= 3) {
			System.out.println(2);

		} else if (N > 3 && N <= 7) {
			System.out.println(4);

		} else if (N > 7 && N <= 15) {
			System.out.println(8);

		} else if (N > 15 && N <= 31) {
			System.out.println(16);

		} else if (N > 31 && N <= 63) {
			System.out.println(32);

		} else if (N > 63 && N <= 100) {
			System.out.println(64);

		}
	}

	// void solve(Scanner sc) {
	// int N = sc.nextInt();
	// int k = 0;
	//
	// for (double i = 1;; i++) {
	// k = (int) Math.pow(2, i);
	// N /= k;
	// if (N == 0) {
	// break;
	// }
	// }
	// System.out.println(k);
	// }
}