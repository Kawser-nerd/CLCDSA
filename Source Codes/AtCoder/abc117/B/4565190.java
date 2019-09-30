import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int max = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			max = Math.max(tmp, max);
			sum += tmp;
		}
		System.out.println(sum - max > max ? "Yes" : "No");
	}
}