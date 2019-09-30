import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		int min = Integer.MAX_VALUE;
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				long x = n / i;
				int f = Math.max(String.valueOf(i).length(), String.valueOf(x).length());
				if (min > f) {
					min = f;
				}
			}
		}
		System.out.println(min);
	}
}