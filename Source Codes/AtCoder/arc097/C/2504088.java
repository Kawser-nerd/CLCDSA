import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Main{

    static class BIT{
        int data[];
        int N;
        void init(int n){
            N=n+1;
            data = new int[N];
        }
        void add(int i,int x){
            for(;i<N;i+=(i&-i))data[i]+=x;
        }
        int sum(int i){
            int res=0;
            for(; i>0;i-=(i&-i))res+=data[i];
            return res;
        }
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N  = scan.nextInt();
        int[] a = new int[2*N];
        int[] Bindex = new int[N+1];
        int[] Windex = new int[N+1];
        for(int i=0;i<2*N;++i){
            String s = scan.next();
            a[i] = scan.nextInt() * (s.equals("B") ? 1:-1);
            if(s.equals("B"))Bindex[a[i]]=i;
            else Windex[-a[i]]=i;
        }

        int[][] Wsum = new int[2*N][N+2];
        int[][] Bsum = new int[2*N][N+2];
        for(int j=1;j<=N;++j){
            for(int i=1;i<2*N;++i){
                Wsum[i][j]=Wsum[i-1][j] + (a[i-1]<0&&Math.abs(a[i-1])<=j ? 1:0);
                Bsum[i][j]=Bsum[i-1][j] + (a[i-1]>0&&a[i-1]<=j ? 1:0);
            }
        }
        for(int i=1;i<2*N;++i){
            Wsum[i][N+1]=N;
            Bsum[i][N+1]=N;
        }


        int[][] dp = new int[N+1][N+1];
        for(int[] d : dp)Arrays.fill(d, Integer.MAX_VALUE/2);
        dp[0][0]=0;
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                if(i>0)dp[i][j]=Math.min(dp[i][j], dp[i-1][j] + (Bindex[i] - Bsum[Bindex[i]][i] - Wsum[Bindex[i]][j]));
                if(j>0)dp[i][j]=Math.min(dp[i][j], dp[i][j-1] + (Windex[j] - Bsum[Windex[j]][i] - Wsum[Windex[j]][j]));
            }
        }
        System.out.println(dp[N][N]);

    }
}