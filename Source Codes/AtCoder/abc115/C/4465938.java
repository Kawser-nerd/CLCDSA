import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		final Scanner scanner = new Scanner(System.in);
		final int counter = scanner.nextInt();
		final int diff = scanner.nextInt();
		final int[] trees = new int[counter];

		for (int i = 0; i < counter; i++) {
			trees[i] = scanner.nextInt();
		}

		Arrays.sort(trees);

		final int[] diffs = new int[counter - diff + 1];
		for (int i = 0; i < counter - diff + 1; i++) {
			diffs[i] = trees[i + diff - 1] - trees[i];
		}

		System.out.println(min(diffs));
	}

	public static int min(int[] array) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < array.length; i++) {
			if (array[i] < min) {
				min = array[i];
			}
		}
		return min;
	}

}