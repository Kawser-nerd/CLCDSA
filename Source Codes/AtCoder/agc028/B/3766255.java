import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        final int mod = ((int)1e9)+7;
        
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        
        for(int i=0; i<n; i++){
            a[i] = Integer.parseInt(sc.next());
        }
        
        //N!
        long k = 1;
        for(int i=1; i<=n; i++){
            k *= i;
            k %= mod;
        }
        
        //???
        long[] r = new long[n+1];
        for(int i=1; i<=n; i++){
            r[i] = (r[i-1] + mod_pow(i,mod-2, mod)) % mod;
        }
        
        //
        long res = 0L;
        for(int i=0; i<n; i++){
            //??+??-???
            res += (r[i+1] + r[n-i] - r[1]) * a[i];
            res %= mod;
        }
        
        //
        System.out.println(res * k % mod);
    }
    
    public static long mod_pow(long x, long p, long m){
        long a = 1;
        while(p>0){
            if(p%2==1){
                a = a*x%m;
            }
            x = x*x%m;
            p /= 2;
        }
        return a;
    }
}