import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        int m = (int)Math.sqrt(N);
        int ans = 100;
        for(int i = m;i > 0;i--){
            if(N%i == 0){
                long A = i;
                long B = N/i;
                int count = 0;
                while(A > 0 || B > 0){
                    A /= 10;
                    B /= 10;
                    count++;
                }
                ans = Math.min(ans, count);
                break;
            }
        }
        System.out.println(ans);
    }
}