import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int H = scanner.nextInt();
			int W = scanner.nextInt();
			scanner.nextLine();
			int h = scanner.nextInt();
			int w = scanner.nextInt();
			scanner.nextLine();
			System.out.println((H - h) * (W - w));
		}
	}
}