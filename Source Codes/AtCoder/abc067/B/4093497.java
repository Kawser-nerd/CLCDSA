import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] map = new int[N];
        for (int i = 0; i < N; i++) {
        	map[i] = sc.nextInt();
        }
        
        Arrays.sort(map);
        int ans = 0;
        for (int i = N-1; N-K <= i; i--) {
        	ans += map[i];
        }
        
        System.out.println(ans);
    }
}