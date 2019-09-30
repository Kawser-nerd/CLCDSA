import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] dp = new int[N+1];
	dp[0] = 0;
	for(int i = 1; i<N+1; i++) {
	    dp[i] = Integer.MAX_VALUE;
	    int power = 1;
	    while(power<=i) {
		dp[i] = Math.min(1+dp[i-power],dp[i]);
		power *= 6;
	    }
	    power=1;
	    while(power<=i) {
		dp[i] = Math.min(1+dp[i-power],dp[i]);
		power *= 9;
	    }
	}
	System.out.println(dp[N]);
    }
}