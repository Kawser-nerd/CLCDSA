import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int color[] = new int[num];
		for(int i = 0; i < num; i ++) {
			color[i] = sc.nextInt();
		}

		int index[] = new int[2 * (int) Math.pow(10, 5) + 10];
		int same[] = new int[num];
		for(int i = 0; i < num; i ++) {
			same[i] = index[color[i]] - 1;
			index[color[i]] = i + 1;
		}
		long dp[] = new long[num];
		dp[0] = 1;
		for(int i = 1; i < num; i ++) {
			if(color[i - 1] == color[i] || same[i] < 0) {
				dp[i] = dp[i - 1];
			}else {
				dp[i] = mod(dp[i - 1] + dp[same[i]]);
			}
		}
		System.out.println(dp[num - 1]);
	}

	static long divisor = (long)Math.pow(10, 9) + 7;
	public static long mod(long i) {
		return i % divisor + ((i % divisor) < 0 ? divisor : 0);
	}
}