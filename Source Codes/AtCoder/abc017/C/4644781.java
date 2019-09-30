import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int sum = 0;
        int[] cum = new int[M+2];
        for (int i = 0; i < N; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int s = sc.nextInt();
            cum[l] += s;
            cum[r+1] -= s;
            sum += s;
        }

        // ???
        for(int m = 1; m <=M; m++  ){
            cum[m] = cum[m-1] + cum[m];
        }

        int max = 0;
        for(int m = 1; m <=M; m++  ){
            max = Math.max(max, sum - cum[m]);
        }

        out.println(max);
    }
}