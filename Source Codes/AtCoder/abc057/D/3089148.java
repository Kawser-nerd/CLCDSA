import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        long[][] nCr = new long[N+1][N+1];
        nCr[0][0]=0;
        for(int row=1;row<=N;row++){
            nCr[row][0] = 1;
            for(int col=1;col<=row-1;col++){
                nCr[row][col] = nCr[row-1][col-1]+nCr[row-1][col];
            }
            nCr[row][row]=1;
        }
        long[] v = new long[N];
        for(int i=0;i<N;i++){
            v[i] = sc.nextLong();
        }
        Arrays.sort(v);
        long sum1 = 0;
        for(int i=N-1;i>=N-A;i--){
            sum1 += v[i];
        }
        double ans1 = sum1/((double)A);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=N-1;i>=0;i--){
            if(v[i]>v[N-A]) cnt1++;
            if(v[i]==v[N-A]) cnt2++;
        }
        long ans2 = 0;
        if(v[N-A]<v[N-1]){
            ans2 = nCr[cnt2][A-cnt1];
        }
        else{
            for(int i=A;i<=Math.min(B,cnt2);i++){
                ans2 += nCr[cnt2][i];
            }
        }
        System.out.println(ans1);
        System.out.println(ans2);
    }
}