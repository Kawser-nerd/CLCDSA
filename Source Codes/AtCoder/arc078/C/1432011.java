import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		System.out.println("? " + (long) 1e10);
		String s = sc.next();
		if (s.equals("Y")) {
			int cnt = 0;
			while (true) {
				System.out.println("? " + (long) (2 * Math.pow(10, cnt)));
				s = sc.next();
				if (s.equals("Y")) {
					System.out.println("! " + (long) Math.pow(10, cnt));
					return;
				}
				++cnt;
			}
		} else {

			int cnt = 9;
			while (true) {
				System.out.println("? " + (long) Math.pow(10, cnt));
				s = sc.next();
				if (s.equals("Y")) {
					break;
				}
				--cnt;
			}
			long left = (long) Math.pow(10, cnt);
			long right = (long) Math.pow(10, cnt + 1) - 1;
			// (left,right]???
			while (right - left > 1) {
				long middle = (right + left) / 2;
				System.out.println("? " + middle * 10);
				s = sc.next();
				if (s.equals("Y")) {
					right = middle;
				} else {
					left = middle;
				}
			}
			System.out.println("! " + right);
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}