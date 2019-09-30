import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        long[] x = new long[N];
        long[] y = new long[N];
        long[] z = new long[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextLong();
            y[i] = sc.nextLong();
            z[i] = sc.nextLong();
        }

        // ??????????????????????????????(8??)??????
        // ???????????????
        long ans = Long.MIN_VALUE;
        for(int i = 0; i < 1<<3; i++){
            Long[] values = new Long[N];
            for(int j = 0; j < N; j++){
                values[j] = add(x[j], (i>>2 & 1) == 1) +
                        add(y[j], (i>>1 & 1) == 1) +
                        add(z[j], (i>>0 & 1) == 1);
            }
            Arrays.sort(values, Collections.reverseOrder());

            long ans_tmp = 0;
            for(int j = 0; j < M; j ++){
                ans_tmp += values[j];
            }

            ans = Math.max(ans, ans_tmp);
        }

        out.println(ans);
    }

    public static long add(long a, boolean isMaximumPlus) {
        if(isMaximumPlus){ return a; }
        return -a;
    }
}