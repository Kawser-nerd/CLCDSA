import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
		int max = x, min = y;
		for (int i = 0; i < n; i++) {
			max = Math.max(max, sc.nextInt());
		}
		for (int i = 0; i < m; i++) {
			min = Math.min(min, sc.nextInt());
		}
		System.out.println(max >= min ? "War" : "No War");
	}
}