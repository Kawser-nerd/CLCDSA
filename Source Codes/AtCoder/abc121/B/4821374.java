import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			int c = scanner.nextInt();
			scanner.nextLine();
			int b[] = new int[m];
			for (int i = 0; i < m; i++) {
				b[i] = scanner.nextInt();
			}
			scanner.nextLine();
			int count = 0;
			for (int i = 0; i < n; i++) {
				int sum = 0;
				for (int j = 0; j < m; j++) {
					int a = scanner.nextInt();
					sum += a * b[j];
				}
				if ((sum + c) > 0) {
					count++;
				}
				scanner.nextLine();
			}
			System.out.println(count);
		}
	}
}