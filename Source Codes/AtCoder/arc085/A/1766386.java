import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		System.out.println((1 << m) * (1900 * m + 100 * (n - m)));
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}