import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        long[] A1 = new long[N];
        long ans = 0;
        long c=0;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
            if(A[i]!=0){
                c+=A[i];
            }else{
                ans+=c/2;
                c=0;
            }
        }
        ans+=c/2;
        System.out.println(ans);
    }
}