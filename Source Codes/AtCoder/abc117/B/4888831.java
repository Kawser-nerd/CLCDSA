import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int[] l = new int[n];
			for (int i = 0; i < n; i++) {
				l[i] = scanner.nextInt();
			}
			scanner.nextLine();
			Arrays.sort(l);
			int sum = 0;
			for (int i = 0; i < n - 1; i++) {
				sum += l[i];
			}
			if (sum > l[n - 1]) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}
}