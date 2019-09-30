import java.util.Scanner;

class Main{

    static long[] factorial;
    static long[] invfac;

    static long mod = (long)1e9+7;
    static long inverse(long m){
        long res =1;
        for(int i=0;i<32;++i){
            if((((mod-2)>>i)&1)==1)res=(res*m)%mod;
            m = (m*m)%mod;
        }
        return res;
    }
    static long C(int i, int j){
        return (((factorial[i]*invfac[i-j])%mod)*invfac[j])%mod;
    }

    static long func(int N, int j){
        //N?j???????
        if(N==j)return factorial[N];
        return ((C(j-1,N-j-1)*factorial[j])%mod*factorial[N-j-1])%mod;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        factorial = new long[N+1];
        factorial[0]=1;
        for(int i=1;i<=N;++i)factorial[i]=(factorial[i-1]*i)%mod;
        invfac = new long[N+1];
        for(int i=0;i<=N;++i)invfac[i]=inverse(factorial[i]);
        long ans = (func(N, (N+1)/2)*((N+1)/2))%mod;
        for(int j=(N+1)/2+1;j<N;++j){
            ans = (ans + j*((func(N, j) - func(N, j-1) + mod)%mod)%mod)%mod;
        }
        System.out.println(ans);
        
    }
}