import java.util.*;

public class Main {
    public static void main(String[] args) {

        int N;
        int [] S = new int[100010];
        int[] tast = new int[100010];

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        for(int i=0; i<N; i++){
            S[i] = sc.nextInt();
        }

        long ans = 0;
        int l = 0, r = 0;

        while(l < N){
            while(r < N && tast[S[r]] == 0){
                tast[S[r]] = 1;
                r++;
            }
            ans = Math.max(ans, r-l);
            tast[S[l]] = 0;
            l++;
        }

        System.out.println(ans);
    }
}