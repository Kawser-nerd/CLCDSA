import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();
        
        int ans = 0;
        ans += N-K >= 0 ? K*X : N*X;
        if (N <= K) {
        	 System.out.println(ans);
        	 return;
        } else {
        	N -= K;
        }
        System.out.println(ans + N*Y);
    }
}