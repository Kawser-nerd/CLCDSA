import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), k = sc.nextInt();
		int s = sc.nextInt(), t = sc.nextInt();
		if (s + t >= k) {
			System.out.println(a * s + b * t - (s + t) * c);
		} else {
			System.out.println(a * s + b * t);
		}
	}
}