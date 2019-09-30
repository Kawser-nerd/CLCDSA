import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] P=new int[N+1];
        int ans=1;
        int max=0;
        for(int i=0;i<N;i++){
            int p=sc.nextInt();
            P[p]=i+1;
        }
        for(int i=2;i<=N;i++){
            if(P[i-1]>P[i]){
                max=Math.max(max, ans);
                ans=1;
            }else{
                ans++;
            }
        }
        max=Math.max(ans,max);
        System.out.println(N-max);
    }
}