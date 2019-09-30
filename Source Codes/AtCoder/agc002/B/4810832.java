import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] x = new int[M];
        int[] y = new int[M];
        for (int i = 0; i < M; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        boolean[] redExists = new boolean[N + 1];
        int[] nums = new int[N + 1];
        redExists[1] = true;
        Arrays.fill(nums, 1);

        for (int i = 0; i < M; i++) {
            if (redExists[x[i]]) {
                if (nums[x[i]] == 1) {
                    redExists[x[i]] = false;
                }

                redExists[y[i]] = true;
            }
            nums[x[i]]--;
            nums[y[i]]++;
        }

        int cnt = 0;
        for (int n = 1; n <= N; n++) {
            if(redExists[n]) {
                cnt++;
            }
        }

        out.println(cnt);
    }
}