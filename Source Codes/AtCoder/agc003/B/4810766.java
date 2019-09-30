import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] cnts = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            cnts[i] = sc.nextLong();
        }

        // ???????????????
        long pairs = 0;
        for (int i = 1; i <= N; i++) {
            if (cnts[i - 1] > 0 && cnts[i] > 0) {
                pairs++;
                cnts[i - 1]--;
                cnts[i]--;
            }
            pairs += cnts[i] / 2;
            cnts[i] %= 2;
        }

        out.println(pairs);
    }
}