import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        
        long[] map = new long[N+1];
        map[0] = 0;
        for (int i = 1; i <= N; i++) {
        	map[i] = sc.nextLong() + map[i-1];
        }
        
        long ans = 0;
        for (int i = 0; i <= N-K; i++) {
        	ans += map[i+K] - map[i];
        }
        
        System.out.print(ans);
    }
    
}