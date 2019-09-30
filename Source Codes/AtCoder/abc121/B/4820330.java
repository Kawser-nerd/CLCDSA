import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		int tmp[] = convertStringToArrayInt(input);
		int N = tmp[0];
		int C = tmp[2];
		int counter = 0;

		input = sc.nextLine();
		int b[] = convertStringToArrayInt(input);

		for (int i = 0; i < N; i++) {
			input = sc.nextLine();
			int arr[] = convertStringToArrayInt(input);
			int source = 0;
			for (int j = 0; j < arr.length; j++) {
				source = source + (b[j] * arr[j]);
			}
			if (source + C > 0) {
				counter++;
			}
		}
		System.out.println(counter);
		sc.close();
	}
	
	private static int[] convertStringToArrayInt(String input) {
		return Arrays.stream(input.split(" ")).filter(s -> !s.isEmpty()).mapToInt(Integer::parseInt).toArray();
	}
}