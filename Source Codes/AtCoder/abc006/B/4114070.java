import java.util.*;

public class Main {
	static final int MOD = 10007;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n == 1 || n == 2) {
			System.out.println(0);
			return;
		} else if (n == 3) {
			System.out.println(1);
			return;
		}
		int a1 = 0;
		int a2 = 0;
		int a3 = 1;
		for (int i = 4; i <= n; i++) {
			int x = a1 + a2 + a3;
			x %= MOD;
			a1 = a2;
			a2 = a3;
			a3 = x;
		}
		System.out.println(a3);
	}
}