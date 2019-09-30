import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int colors = 1000002;
        int[] likes = new int[colors];

        for (int i = 0; i < n; i++) {
            likes[sc.nextInt()]++;
            likes[sc.nextInt() + 1]--;
        }

        for (int i = 1; i < colors; i++) {
            likes[i] = likes[i - 1] + likes[i];
        }

        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < colors; i++) {
            ans = Math.max(ans, likes[i]);
        }

        out.println(ans);
    }
}