import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long a = sc.nextLong();
		long b = sc.nextLong();

		if (a > b) {
			System.out.println("Takahashi");
		} else if (a == b) {
			if (n % (a + 1) != 0) {
				System.out.println("Takahashi");
			} else {
				System.out.println("Aoki");
			}
		} else {
			if (n <= a) {
				System.out.println("Takahashi");
			} else {
				System.out.println("Aoki");
			}
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}