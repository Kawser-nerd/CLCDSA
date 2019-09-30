import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		// A<=B
		while (A > 0 && Long.highestOneBit(A) == Long.highestOneBit(B)) {
			long flip = Long.highestOneBit(A);
			A ^= flip;
			B ^= flip;
		}
		if (B == 0) {
			System.out.println(1);
			return;
		}
		int first = Long.numberOfTrailingZeros(Long.highestOneBit(B));
		int second = -1;
		if (B == (1L << first)) {
			second = -1;
		} else {
			second = Long.numberOfTrailingZeros(Long.highestOneBit(B ^ (1L << first)));
		}
		long l1 = A;
		long r1 = ((1L << first) + ((1L << (second + 1)) - 1));
		long l2 = A + (1L << first);
		long r2 = (1L << (first + 1)) - 1;
		long res = -1;
		if (l2 <= r1 && r1 <= r2) {
			res = r2 - l1 + 1;
		} else if (l1 <= r2 && r2 <= r1) {
			res = r1 - l1 + 1;
		} else if (r1 <= l2) {
			res = (r1 - l1 + 1) + (r2 - l2 + 1);
		}
		System.out.println(res);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}