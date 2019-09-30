import java.util.*;

public class Main {
    static long mod = 1000000000+7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        int maxn = n+k-1;
        long[] inv = new long[maxn+1];
        long[] frac = new long[maxn+1];
        inv[0] = frac[0] = 1;
        for(int i=1;i<=maxn;i++) frac[i] = i*frac[i-1]%mod;
        inv[maxn] = pow(frac[maxn],mod-2);
        for(int i=maxn-1;i>=1;i--) inv[i] = (i+1)*inv[i+1]%mod;
        long ans = frac[maxn]*inv[k]%mod*inv[n-1]%mod;
        System.out.println(ans);
    }
    static long pow(long base, long p){
        long ans = 1;
        while(p>0){
            if(p%2==1) ans = ans*base%mod;
            base = base*base%mod;
            p /= 2;
        }
        return ans;
    }
}