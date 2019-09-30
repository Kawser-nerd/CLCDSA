import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt(), x = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		for (int i = 0; i < n; i++) {
			x -= a[i];
			if (x < 0) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(x == 0 ? n : n - 1);
	}
}