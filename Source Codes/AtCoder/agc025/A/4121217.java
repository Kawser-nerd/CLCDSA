import java.util.*;

public class Main {
	static int[][][] dp;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int min = Integer.MAX_VALUE;
		for (int i = 1; i <= n / 2; i++) {
			int a = n - i;
			int b = i;
			int sum = 0;
			while (a > 0) {
				sum += a % 10;
				a /= 10;
			}
			while (b > 0) {
				sum += b % 10;
				b /= 10;
			}
			if (min > sum) {
				min = sum;
			}
		}
		System.out.print(min);
	}
}