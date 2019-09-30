import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	final long MODULO = 1_000_000_000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		if (n < m) {
			int d = n;
			n = m;
			m = d;
		}
		if (Math.abs(n - m) >= 2) {
			System.out.println(0);
			return;
		}
		long ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = (ans * i) % MODULO;
		}
		for (int i = 1; i <= m; ++i) {
			ans = (ans * i) % MODULO;
		}
		if (n == m) {
			ans = (ans * 2) % MODULO;
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}