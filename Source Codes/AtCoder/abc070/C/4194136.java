import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long[] arr = new long[sc.nextInt()];

		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextLong();
		}
		sc.close();

		System.out.println(lcd(arr));
	}

	private static long lcd(long[] arr) {

		if (arr.length == 1) {

			return arr[0];
		} else if (arr.length == 2) {

			return arr[0] * (arr[1] / gcd(arr[0], arr[1]));
		} else {

			long temp = arr[0] * (arr[1] / gcd(arr[0], arr[1]));

			for (int i = 2; i < arr.length; i++) {

				temp = temp * (arr[i] / gcd(temp, arr[i]));
			}

			return temp;
		}
	}

	private static long gcd(long m, long n) {

		if (m < n) {
			return gcd(n, m);
		}

		if (n == 0) {
			return m;
		}

		return gcd(n, m % n);
	}
}