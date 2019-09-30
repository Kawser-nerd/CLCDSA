import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		sc.close();
		String s = Long.toString(N);
		int l = s.length();
//		int[][] dp = new int[l + 1][2];
//		dp[1][0] = s.charAt(0) - '0';
//		dp[1][1] = s.charAt(0) - '0' - 1;
//		for(int i = 0; i < l; i++) {
//			if(s.charAt(i) == '1') {
//
//			}
//		}
		int cnt = 0;
		int max = 0;
		for(int i = 0; i < l; i++) {
			char c = s.charAt(i);
			if(c == '9') {
				cnt++;
			}
			max += c - '0';
		}
		if(cnt == l) {
			System.out.println(l * 9);
			System.exit(0);
		}
		int k = (l - 1) * 9 + s.charAt(0) - '0' - 1;
		max = Math.max(max, k);
		System.out.println(max);

	}
}