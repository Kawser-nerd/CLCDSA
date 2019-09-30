import java.util.*;

public class Main{
    
    static final int MOD = 1_000_000_007;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        double n = sc.nextInt();
        double k = sc.nextInt();
        
        double ans = ((k-1)*(n-k)*6 + (n-1)*3 + 1)/n/n/n;
        
        System.out.println(ans);
    }
}