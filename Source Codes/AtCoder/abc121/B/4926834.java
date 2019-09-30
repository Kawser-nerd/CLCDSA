import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			int c = scanner.nextInt();
			scanner.nextLine();
			int b[] = new int[m];
			IntStream.range(0, m).forEach(i -> b[i] = scanner.nextInt());
			scanner.nextLine();
			System.out.println(IntStream.range(0, n).filter(i -> {
				int sum = IntStream.range(0, m).map(j -> scanner.nextInt() * b[j]).sum();
				scanner.nextLine();
				return (sum + c) > 0;
			}).count());
		}
	}
}