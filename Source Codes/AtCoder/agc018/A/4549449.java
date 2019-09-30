import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int max = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (max < a) {
				max = a;
			}
			if (i == 0) {
				last = a;
			} else {
				last = gcd(last, a);
			}
		}
		if (k <= max && k % last == 0) {
			System.out.println("POSSIBLE");
		} else {
			System.out.println("IMPOSSIBLE");
		}
	}
	
	static int gcd(int x, int y) {
		if (x % y == 0) {
			return y;
		} else {
			return gcd(y, x % y);
		}
	}
}