import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int s = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
			s += a[i];
		}
		BigInteger can = BigInteger.ONE;
		for (int i = 0; i < n; ++i) {
			can = can.shiftLeft(a[i]).or(can);
		}
		for (int i = (s + 1) / 2; i <= s; ++i) {
			if (can.testBit(i)) {
				System.out.println(i);
				return;
			}
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
}