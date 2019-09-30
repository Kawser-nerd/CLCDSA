import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();

		int[] x = new int[n + 1];
		int[] y = new int[m + 1];

		x[n] = X;
		y[m] = Y;

		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			y[i] = sc.nextInt();
		}

		Arrays.sort(x);
		Arrays.sort(y);

		System.out.println(x[n] < y[0] ? "No War" : "War");

		sc.close();
	}

}