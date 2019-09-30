import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();

		int [] arr = new int[n*2];

		for (int i = 0; i < n*2; i++) {
			arr[i] = scanner.nextInt();
		}

		Arrays.sort(arr);

		int sum = 0;

		for (int i = 1; i < n*2; i+=2) {
			sum += Math.min(arr[i-1], arr[i]);
		}

		System.out.println(sum);
	}
}