import java.util.*;

class Main {
    static long MOD=1000000007;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long n=scan.nextLong();
        int B=62;
        long[][]dp=new long[3][B];
        dp[0][B-1]=1;
        for(int i=B-2;i>=0;--i){
            for(int a=0;a<=2;++a){
                if(n>>>i<a)continue;
                long m=n>>>i;
                int b=(int)(m/2-(m-a)/2);
                int c=(int)((m-a)%2);
                if(c!=0)
                    dp[a][i]=dp[b][i+1]%MOD;
                else
                    dp[a][i]=(dp[b][i+1]+dp[b+1][i+1])%MOD;
            }
        }
        long[] r=new long[B],s=new long[B];
        r[0]=1;s[0]=0;
        for(int i=1;i<B;++i)r[i]=(3*r[i-1]+MOD-1)%MOD;
        for(int i=1;i<B;++i)s[i]=(3*s[i-1]+1)%MOD;
        long t=0;
        for(int i=B-2;i>=0;--i){
            if((n&1L<<i)!=0){
                t+=dp[1][i]*r[i]%MOD;
                t+=dp[2][i]*s[i]%MOD;
                t%=MOD;
            }
        }
        t=(t+dp[0][0])%MOD;
        System.out.println(t);
    }
}