import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		long[] T = new long[N];
		T[0] = sc.nextLong();
		long lcm = T[0];
		for (int i = 1; i < N; i++) {
			T[i] = sc.nextLong();
			lcm = lcm(lcm, T[i]);
		}
		System.out.println(lcm);
		sc.close();
	}

	private long lcm(long l1, long l2) {
		if (l1 < l2) {
			return lcm(l2, l1);
		}
		long gcd = gcd(l1, l2);
		return (l1 / gcd) * (l2 / gcd) * gcd;

	}

	private long gcd(long l1, long l2) {
		if (l1 < l2) {
			return gcd(l2, l1);
		} else if (l2 == 0) {
			return l1;
		} else {
			long r = l1 % l2;
			return gcd(l2, r);
		}

	}
}