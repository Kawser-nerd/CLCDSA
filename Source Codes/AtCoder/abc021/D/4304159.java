/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Init(1000000);
        out.println(combi(n-1+k,n-1));
    }
    static long power(long x,int n){
        long mod=1000000007;
        if(n==0)return 1;
        if(n%2==0){
            long e=power(x,n/2)%mod;
            return (e*e)%mod;
        }
        return (x*power(x,n-1))%mod;
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
}