import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();

		long mod = 1000000007;
		long[] cnt = new long[26];
		for (int i = 0; i < N; i++) {
            //System.out.println(S.charAt(i) - 'a');
			cnt[S.charAt(i) - 'a']++;
		}
		long ans = 1;
		for (long i : cnt) {
			ans = (i+1)*ans%mod;
		}
		ans -= 1;
		System.out.println(ans);
	}
}