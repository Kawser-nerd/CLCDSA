import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(final String[] args) {
		final Scanner scanner = new Scanner(System.in);
		final int num = scanner.nextInt();
		final int point = scanner.nextInt();

		if (num >= point) {
			System.out.println(0);
			return;
		}

		final int[] points = new int[point];

		for (int i = 0; i < point; i++) {
			points[i] = scanner.nextInt();
		}

		int sum = 0;
		final int[] diffs = new int[point - 1];

		Arrays.sort(points);

		for (int i = 0; i < point - 1; i++) {
			final int diff = points[i + 1] - points[i];
			sum += diff;
			diffs[i] = diff;
		}

		Arrays.sort(diffs);

		int reducible = 0;

		for (int i = diffs.length - num + 1; i < diffs.length; i++) {
			reducible += diffs[i];
		}

		System.out.println(sum - reducible);
	}

}