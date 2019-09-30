import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int size=1000000;
        long[] fact=new long[size];
        long[] inv=new long[size];
        fact[0]=1;
        inv[0]=1;
        long mod=1000000007;
        for (int i = 1; i < size; i++) {
            fact[i]=(fact[i-1]*i)%mod;
            inv[i]=power(fact[i],(int)mod-2)%mod;
        }
        //comb=fact[n]*inv[k]%mod*inv[n-k]%mod
        int n=sc.nextInt();
        int m=sc.nextInt();
        if(m==1){
            out.println(1);
        }else{
            HashMap<Integer,Integer> map=new HashMap<>();
            int stop=(int)sqrt(m)+1;
          for (int i = 2; i <=stop; i++) {
                while(m%i==0){
                    m/=i;
                    map.put(i,map.getOrDefault(i, 0)+1);
                }
            }
          if(m!=1)map.put(m,1);
            long ans=1;
            for(int k:map.keySet()){
                ans=(ans%mod*fact[n-1+map.get(k)]%mod*inv[n-1]%mod*inv[map.get(k)]%mod)%mod;
            }
            out.println(ans);
        }
      }
    static long power(long x,int n){
        long mod=1000000007;
        long ans=1;
        while (n>0) {
            if((n&1)==1){
                ans=(ans%mod*x%mod)%mod;
            }
            x=(x%mod*x%mod)%mod;
            n>>=1;
        }
        return ans;
    }
}