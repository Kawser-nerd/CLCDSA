import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// standard input
		int numBoxes = sc.nextInt();
		int numLimit = sc.nextInt();
		int[] candyArray = new int[numBoxes];
		for (int i = 0; i < numBoxes; i++) {
			candyArray[i] = sc.nextInt();
		}

		//
		long totalAteCandies = 0;
		for (int i = 1; i < numBoxes; i++) {
			int numExcessCandies = calculateExcessCandies(numLimit, candyArray[i - 1], candyArray[i]);
			totalAteCandies += numExcessCandies;
			eatCandies(candyArray, i, numExcessCandies);
		}
		System.out.println(totalAteCandies);
	}

	public static int calculateExcessCandies(int limit, int candy1, int candy2) {
		int numCandies = candy1 + candy2 - limit;
		if (numCandies < 0) {
			return 0;
		} else {
			return numCandies;
		}
	}

	public static void eatCandies(int[] array, int index, int numExcessCandies) {
		array[index] -= numExcessCandies;
		if (array[index] < 0) {
			array[index - 1] += array[index];
			array[index] = 0;
		}
	}
}