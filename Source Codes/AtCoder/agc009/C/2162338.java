import java.util.Scanner;

class Main{

    static int N;
    static long A,B;
    static long[] S;

    static int findIndex(long s){
        int left=0,right=N+1;
        while(right-left>1){
            int center=(left+right)/2;
            if(s-S[center]>=B)left=center;
            else right=center;
        }
        return left;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        A = scan.nextLong();
        B = scan.nextLong();
        S = new long[N+1];
        long[] sum=new long[N+1];
        sum[0]=1;
        S[0] = -B;
        for(int i=1;i<=N;++i)S[i]=scan.nextLong();
        int lindex=-1;
        long mod = (long)1e9+7;
        if(A>B){
            long a = A;
            A=B;
            B=a;
        }
        for(int i=2;i<=N;++i)if(S[i]-S[i-2]<A){
            System.out.println(0);
            return;
        }

        for(int i=1;i<=N;++i){
            if(S[i]-S[i-1]<A){
                //??? findindex?lindex???????????
                int index = findIndex(S[i]);
                long dp = (index >= lindex ? (sum[findIndex(S[i])] - (lindex>=0 ? sum[lindex]:0)+mod)%mod : 0);
                sum[i]=(sum[i-1]+dp)%mod;
                lindex=i-2;
            }else if(S[i]-S[i-1]<B){
                int index = findIndex(S[i]);
                long dp = (index >= lindex ? (sum[findIndex(S[i])] - (lindex>=0 ? sum[lindex]:0)+mod)%mod : 0);
                sum[i]=(sum[i-1]+dp)%mod;
            }else{
                long dp = (sum[i-1] - (lindex>=0 ? sum[lindex]:0)+mod)%mod;
                sum[i]=(sum[i-1]+dp)%mod;
            }
        }
        System.out.println(((sum[N]-(lindex>=0 ? sum[lindex]:0)+mod)%mod));
    }
}