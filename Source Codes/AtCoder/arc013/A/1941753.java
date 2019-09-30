import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int l = sc.nextInt();
		int p = sc.nextInt();
		int q = sc.nextInt();
		int r = sc.nextInt();
		int max = 0;
		max = Math.max((n / p) * (m / q) * (l / r), max);
		max = Math.max((n / p) * (m / r) * (l / q), max);
		max = Math.max((n / q) * (m / p) * (l / r), max);
		max = Math.max((n / q) * (m / r) * (l / p), max);
		max = Math.max((n / r) * (m / q) * (l / p), max);
		max = Math.max((n / r) * (m / p) * (l / q), max);
		System.out.println(max);

	}
}