import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int h=sc.nextInt();
        int w=sc.nextInt();
        Init(200000);
        out.println(combi(h+w-2,w-1));
    }
    static int mod=1000000007;
    static long[] fact;
    static long[] inv;
    static void Init(int n){
        fact=new long[n];
        inv=new long[n];
        fact[0]=inv[0]=1;
        for (int i = 1; i < n; i++) {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=power(fact[i], mod-2);
        }
    }
    static long combi(int n,int k){
        return ((fact[n]*inv[n-k])%mod*inv[k])%mod;
    }
    static long power(long x,int n){
        if(n==0)return 1;
        if(n%2==0){
            long e=power(x,n/2)%mod;
            return (e*e)%mod;
        }
        long e=power(x,(n-1)/2)%mod;
        return ((e*x)%mod*e)%mod;
        /*
        long e=(x*power(x,n-1))%mod;
        return e;
        */
    }
}