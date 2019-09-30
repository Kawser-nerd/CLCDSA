import java.util.Scanner;


public class A {
	long sd(long a, long b) {
		if (b == 0) {
			return a;
		}
		long c = a%b;
		return sd(b, c);
	}

	void run() {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t=1; t<=T; t++) {
			String str = in.next();
			String[] strs = str.split("/");
			long a = Long.valueOf(strs[0]);
			long b = Long.valueOf(strs[1]);
			long s = sd(a, b);
			a /= s;
			b /= s;
			if ((b&(b-1)) == 0) {
				int res = 0;
				for (; a < b; res++) {
					a *= 2;
				}
				System.out.println("Case #" + t + ": " + res);
			} else {
				System.out.println("Case #" + t + ": impossible");
			}
		}
	}

	static public void main(String[] args) {
		new A().run();
	}
}
