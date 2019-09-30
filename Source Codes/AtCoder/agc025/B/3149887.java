import java.util.*;

class Main{
    static int maxN = 300000+5;
    static final long Mod = 998244353;
    static long[] frac = new long[maxN+1];
    static long[] inv = new long[maxN+1];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        long K = sc.nextLong();
        long[] res = new long[N+1];
        initial();
        for(int a=0;a<=N;a++){
            if(K-(long)a*A==0){
                res[a]=com(N,a);
                continue;
            }
            if((K-(long)a*A)%B!=0) continue;
            long b = (K-(long)a*A)/(long)B;
            if(b<0||b>N) continue;
            res[a]=com(N,a)*com(N,(int)b)%Mod;
        }
        long ans = 0;
        for(int i=0;i<=N;i++) ans = (ans+res[i])%Mod;
        System.out.println(ans);

    }
    static long QucikPower(long a, long pow){
        long ans = 1;
        long base = a;
        while(pow!=0){
            if(pow%2==1) ans = ans*base%Mod;
            base=base*base%Mod;
            pow/=2;
        }
        return ans;
    }
    static void initial(){
        frac[0]=1;
        for(int i=1;i<=maxN;i++) frac[i]=(frac[i-1]*i)%Mod;
        inv[0]=1;
        inv[maxN] = QucikPower(frac[maxN],Mod-2);
        for(int i=maxN-1;i>=1;i--){
            inv[i]=inv[i+1]*(i+1)%Mod;
        }
    }
    static long com(int N, int a){
        return frac[N]*inv[a]%Mod*inv[N-a]%Mod;
    }
}