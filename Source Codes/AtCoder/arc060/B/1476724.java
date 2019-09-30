import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long s = sc.nextLong();
		long sqrt = (long) (Math.sqrt(n));
		for (int b = 2; b <= sqrt; ++b) {
			if (f(n, b) == s) {
				System.out.println(b);
				return;
			}
		}
		if (n - s == 0) {
			System.out.println(n + 1);
			return;
		}

		ArrayList<Long> div = new ArrayList<>();
		for (long i = 1; i * i <= n - s; ++i) {
			if ((n - s) % i == 0) {
				div.add(i);
				div.add((n - s) / i);
			}
		}
		Collections.sort(div);
		for (long v : div) {
			if (f(n, v + 1) == s) {
				System.out.println(v + 1);
				return;
			}
		}
		System.out.println(-1);
	}

	long f(long n, long b) {
		long ret = 0;
		while (n > 0) {
			ret += n % b;
			n /= b;
		}
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}