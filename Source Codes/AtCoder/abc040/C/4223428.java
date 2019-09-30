import java.util.*;
import static java.lang.System.*;

// https://atcoder.jp/contests/abc040/tasks/abc040_c
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) a[i] = sc.nextInt();

        solver(N, a);
    }

    public static void solver(int N, int[] a) {
        int[] ans = new int[N];

        for(int n = N-1; n >= 0; n--){
            if(n == N-1){
                continue;
            } else if (n == N-2){
                ans[n] = Math.abs(a[n]-a[n+1]);
            } else if (n == N-3){
                ans[n] = Math.abs(a[n]-a[n+2]);
            } else {
                ans[n] = Math.min(
                        Math.abs(ans[n+1] + Math.abs(a[n]-a[n+1])),
                        Math.abs(ans[n+2] + Math.abs(a[n]-a[n+2]))
                        );
            }

        }
        out.println(ans[0]);
    }
}