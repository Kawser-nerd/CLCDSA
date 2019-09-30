import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static int solve() {
		sc.nextInt();
		char[] S = sc.next().toCharArray();
		int ret = 0;
		int sum = 0;
		for (int i = 0; i < S.length; ++i) {
			int num = S[i] - '0';
			if (num > 0 && sum < i) {
				ret += i - sum;
				sum = i;
			}
			sum += num;
		}
		return ret;
	}

}
