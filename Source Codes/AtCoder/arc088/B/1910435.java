import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

class Main {

	final long MOD = 1_000_000_000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int n = S.length();
		int ans = n / 2;
		int left = n - ans - 1;
		int right = ans;
		char c = S.charAt(left);

		while (left >= 0 && S.charAt(left) == S.charAt(right) && S.charAt(left) == c) {
			--left;
			++right;
			++ans;
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
}