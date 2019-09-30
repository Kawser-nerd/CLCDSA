import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();	
        
        int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		
		
		int[] dp = new int[N];
		dp[1] = Math.abs(map[1] - map[0]);
		for (int i = 2; i < N; i++) {
			dp[i] = Math.min(dp[i-1] + Math.abs(map[i] - map[i-1]), dp[i-2] + Math.abs(map[i] - map[i-2]));
		}
		
		System.out.println(dp[N-1]);
    }
}