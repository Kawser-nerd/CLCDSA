import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int ans = 0;
        int now = sc.nextInt();
        int max = Integer.MAX_VALUE;
        for (int i = 1; i < N; i++) {
        	int a = sc.nextInt();
        	if (a == now) {
        		ans++;
        		now = max;
        	} else {
        		now = a;
        	}
        }
        
        System.out.println(ans);
    }
}