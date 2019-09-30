import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int[] l = new int[n];
			IntStream.range(0, n).forEach(i -> l[i] = scanner.nextInt());
			scanner.nextLine();
			Arrays.sort(l);
			int sum = Arrays.stream(l).limit(n - 1).sum();
			if (sum > l[n - 1]) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}
}