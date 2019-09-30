import java.util.*;
import java.lang.*;

public class Main {
	static long mod = 1000000007;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		long ans = 1;
		for (int i = 1; i <= h + w - 2; i++) {
			ans = ans * i % mod;
		}
		for (int i = 1; i <= h - 1; i++) {
			ans = ans * power(i, mod - 2) % mod;
		}
		for (int i = 1; i <= w - 1; i++) {
			ans = ans * power(i, mod - 2) % mod;
		}
		System.out.println(ans);
	}
	static long power(long a, long b) {
		if (b == 0) {
			return 1;
		}
		if (b % 2 == 0) {
			return power(a * a % mod, b / 2) % mod;
		} else {
			return power(a, b - 1) * a % mod;
		}
	}
}