package Round1A2016;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final int n = sc.nextInt();
            int[] bff = new int[n];
            boolean[] hasIncoming = new boolean[n];
            for (int i = 0; i < n; ++i) {
                bff[i] = sc.nextInt() - 1;
                hasIncoming[bff[i]] = true;
            }
            int[] loop = new int[n];
            int maxPeriod = 0;
            for (int i = 0; i < n; ++i) {
                boolean[] visited = new boolean[n];
                int cur = 0;
                int[] index = new int[n];
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    index[j] = cur++;
                    j = bff[j];
                }
                final int period = cur - index[j];
                for (int k = 0; k < period; ++k) {
                    loop[j] = period;
                    j = bff[j];
                }
                maxPeriod = Math.max(maxPeriod, period);
            }
            int[] maxChain = new int[n];
            for (int i = 0; i < n; ++i) {
                if (hasIncoming[i])
                    continue;
                int j = i;
                int chain = 0;
                while (loop[j] == 0) {
                    ++chain;
                    j = bff[j];
                }
                maxChain[j] = Math.max(maxChain[j], chain);
            }
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (loop[i] == 2) {
                    sum += 1 + maxChain[i];
                }
            }
            System.out.printf("Case #%d: %d\n", testCase, Math.max(sum, maxPeriod));
        }
    }
}