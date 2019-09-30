import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] arr = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += x % 2 * sc.nextInt();
			x /= 2;
		}
		System.out.println(sum);
	}
}