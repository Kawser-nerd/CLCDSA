import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int z = sc.nextInt();
		int w = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
		}
		if (n >= 2) {
			System.out.println(Math.max(Math.abs(w - a[n - 1]), Math.abs(a[n - 1] - a[n - 2])));
		} else if (n == 1) {
			System.out.println(Math.abs(w - a[0]));
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}