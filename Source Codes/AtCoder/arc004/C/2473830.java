import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String[] s = in.next().split("/");
		long x = Long.parseLong(s[0]);
		long y = Long.parseLong(s[1]);

		long g = gcd(x, y);
		x /= g;
		y /= g;

		boolean isFound = false;

		if (x < y) {
			System.out.println("Impossible");
			return;
		}

		for (int i = 0; i < 2; i++) {
			long n = 2*x/y+i;
			if (n % y == 0) {
				long m = n*(n+1)/2-n/y*x;
				if (1 <= m && m <= n) {
					System.out.println(n +" "+ m);
					isFound = true;
				}
			}
		}

		if (!isFound) {
			System.out.println("Impossible");
		}
	}

	public static long gcd(long a, long b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

}