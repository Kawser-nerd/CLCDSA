import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[] s = new long[n];
		boolean flg = false;
		for (int i = 0; i < n; i++) {
			s[i] = sc.nextLong();
			if (s[i] == 0) {
				flg = true;
			}
		}
		sc.close();

		if (flg) {
			System.out.println(n);
			return;
		}

		int ans = 0;
		int start = 0;
		int end = 0;
		long val = 1;
		for (int i = 0; i < n; i++) {
			val *= s[i];
			end = i;
			while (val > k && start <= end) {
				val /= s[start];
				start++;
			}
			ans = Math.max(ans, end - start + 1);
		}
		System.out.println(ans);
	}
}