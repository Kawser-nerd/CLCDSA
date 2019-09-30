import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String[] n = sc.next().split("");
		int sum = Arrays.stream(n)
				.mapToInt(Integer::parseInt)
				.sum();
		System.out.println(sum == 1 ? 10 : sum);
	}
}