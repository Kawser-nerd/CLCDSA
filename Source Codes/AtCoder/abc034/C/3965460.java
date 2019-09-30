import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int W=sc.nextInt();
        int H=sc.nextInt();
        int size=10000000;
        long[] fact=new long[size];
        long[] inv=new long[size];
        fact[0]=1;
        inv[0]=1;
        long mod=1000000007;
        for (int i = 1; i < size; i++) {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=power(fact[i],(int)mod-2)%mod;
        }
        int n=W+H-2;
        int k=W-1;
        out.println(fact[n]%mod*inv[k]%mod*inv[n-k]%mod);
        //comb=fact[n]*inv[k]%mod*inv[n-k]%mod
    }
    static long power(long x,int n){
        long mod=1000000007;
        long ans=1;
        while (n>0) {
            if((n&1)==1){
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            n>>=1;
        }
        return ans;
    }
}