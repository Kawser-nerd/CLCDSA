import java.util.HashSet;
import java.util.Scanner;

public class Main {
	void run() {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while (t-- != 0) {
			long a = scan.nextLong();
			long b = scan.nextLong();
			long c = scan.nextLong();
			long d = scan.nextLong();
			System.out.println(eval(a, b, c, d) ? "Yes" : "No");
		}
	}
	boolean eval(long a, long b, long c, long d) {
		if (b > a || b > d)
			return false;
		if (c >= b)
			return true;
		if (b - gcd(b, d) + (a % gcd(b, d)) > c)
			return false;
		else
			return true;
	}
	long gcd(long a, long b) {
		if (a % b == 0)
			return b;
		return gcd(b, a % b);
	}
	public static void main(String[] args) {
		new Main().run();
	}
}