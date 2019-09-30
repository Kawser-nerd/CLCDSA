import java.util.Arrays;
import java.util.Scanner;

public class Main {

	class Magic implements Comparable<Magic> {
		int up;
		int down;

		@Override
		public int compareTo(Magic m) {

			int result = up - down;
			int result1 = m.up - m.down;
			if (result >= 0 && result1 < 0) {
				return 1;
			} else if (result < 0 && result1 >= 0) {
				return -1;
			} else if (result < 0 && result1 < 0) {
				return up - m.up;
			} else {
				return -(down - m.down);
			}
		}
	}

	// ???????????????

	void run() {
		Scanner sc = new Scanner(System.in);

		// input
		int n = sc.nextInt();

		Magic[] magics = new Magic[n];

		for (int i = 0; i < n; i++) {
			magics[i] = new Magic();
		}

		for (int i = 0; i < n; i++) {
			magics[i].up = sc.nextInt();
			magics[i].down = sc.nextInt();
		}

		// sort
		Arrays.sort(magics);

		long max = 0;
		long tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += magics[i].up;
			max = Math.max(tmp, max);
			tmp -= magics[i].down;
			max = Math.max(tmp, max);
		}

		System.out.println(max);
	}

	public static void main(String[] args) {
		new Main().run();
	}

}