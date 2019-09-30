import java.util.*;

class Main {
    static long f(long a){
        int[] d=new int[19];
        long b=a;
        for(int i=0;i<19;++i){
            d[18-i]=(int)(a%10);
            a/=10;
        }
        long[] dp=new long[20];
        boolean f=false;
        for(int i=0;i<19;++i){
            dp[i+1]=8*dp[i];
            for(int k=d[i]+1;k<10;++k){
                if(k!=4&&k!=9&&!f)
                    dp[i+1]--;
            }
            if(d[i]==4||d[i]==9)f=true;
        }
        return b+1-dp[19];
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long a=scan.nextLong();
        long b=scan.nextLong();
        System.out.println(f(b)-f(a-1));
    }
}