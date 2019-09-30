import java.util.*;

public class Main{
    public static void main(String[] args){
            
        Scanner sc = new Scanner(System.in);		                                        
           
        int n = sc.nextInt();
        
        long[] a = new long[n];
        
        for(int i = 0;i < n;i++){
            a[i] = sc.nextLong();
        }
                   
        long sum = 0;
        long cost = 0;
        long ans = Long.MAX_VALUE;
        // +-+-
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 0) {
                if (sum <= 0) {
                    cost += -sum + 1;
                    sum = 1;
                }
            } else {
                if (sum >= 0) {
                    cost += sum + 1;
                    sum = -1;
                }
            }
        }
        ans = Math.min(ans, cost);
        sum = 0;
        cost = 0;
        // -+-+
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 0) {
                if (sum >= 0) {
                    cost += sum + 1;
                    sum = -1;
                }
            } else {
                if (sum <= 0) {
                    cost += -sum + 1;
                    sum = 1;
                }
            }
        }
        ans = Math.min(ans, cost);
        System.out.println(ans);           
                      
    }    
    
}