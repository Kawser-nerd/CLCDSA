import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		int s = 0;
		int t = 0;
		long max = 0;
		for (int i = 0; i < n; i++) {
			if (i == s) {
				continue;
			}

			System.out.printf("? %d %d\n", s+1, i+1);
			Scanner scanner = new Scanner(System.in);
			long dist = scanner.nextLong();
			if (max < dist) {
				max = dist;
				t = i;
			}
		}

		s = t;
		max = 0;
		for (int i = 0; i < n; i++) {
			if (i == s) {
				continue;
			}

			System.out.printf("? %d %d\n", s+1, i+1);
			Scanner scanner = new Scanner(System.in);
			long dist = scanner.nextLong();
			if (max < dist) {
				max = dist;
			}
		}

		System.out.printf("! %d\n", max);

		in.close();
	}
}