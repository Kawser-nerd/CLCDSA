import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] cnt = new int[2]; //0: even numbers, 1: odd numbers
        for (int i = 0; i < N; i++) {
            cnt[(int) (sc.nextLong() % 2)]++;
        }

        int restOdd = cnt[1] % 2;
        cnt[0] += cnt[1] / 2;

        if ((restOdd == 0 && cnt[0] > 0) || (restOdd == 1 && cnt[0] == 0)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }
}