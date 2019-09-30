import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        long a = Integer.parseInt(sc.next());
        long b = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        
        int mod = 998244353;
        int max = 300_003;
        Mod_nCr mn = new Mod_nCr(mod, max);
        
        long ans = 0;
        for(int red=0; red<=n; red++){
            int blue = (int)((k-red*a)/b);
            if(red*a + blue*b == k && 0<=blue){
                ans += mn.nCr(n, red) * mn.nCr(n, blue);
                ans %= mod;
            }
        }
        
        System.out.println(ans);
    }
}

class Mod_nCr{
    int mod;
    long[] fact;
    long[] rfact;
    
    public Mod_nCr(int mod, int max){
        this.mod = mod;
        fact = new long[max];
        rfact = new long[max];
        
        fact[0] = 1;
        rfact[0] = 1;
        
        for(int i=1; i<max; i++){
            fact[i] = (fact[i-1]*i)%mod;
            rfact[i] = mod_inverse(fact[i], mod);
        }
    }
    
    //
    private long mod_pow(long x, long p, long m){
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
    
    private long mod_inverse(long a, long m){
        return mod_pow(a, m-2, m);
    }
    
    //
    public long nCr(int n, int r){
        if(n < r) return 0;
        return fact[n]*rfact[r]%mod * rfact[n-r]%mod;
    }
}