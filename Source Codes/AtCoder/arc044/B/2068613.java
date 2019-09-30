import java.util.*;

public class Main{
    
    static final int MOD = 1_000_000_007;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] d = new int[n];
        int dmax = 0;
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
            d[a[i]]++;
            dmax = Math.max(a[i], dmax);
        }
        
        if(a[0]!=0 || d[0]!=1){
            System.out.println(0);
            return;
        }
        
        for(int i=0; i<=dmax; i++){
            if(d[i]==0){
                System.out.println(0);
                return;
            }
        }
        
        long ans = 1L;
        
        for(int i=1; i<=dmax; i++){
            long tmp = pow(2, d[i-1]);
            tmp = (tmp+MOD-1)%MOD;
            ans = (ans*pow(tmp, d[i]))%MOD;
            ans = (ans*pow(2, (long)(d[i]-1)*d[i]/2))%MOD;
        }
        
        System.out.println(ans);
    }
    
    public static long pow(long a, long n){
        long x = 1;
        while(n>0){
            if(n%2==1){
                x = x*a%MOD;
            }
            a = a*a%MOD;
            n >>= 1;
        }
        return x;
    }
    
}