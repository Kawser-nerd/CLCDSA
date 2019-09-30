import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        // m???????-1??????f(m)?a[i]-1???????m????????
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += a[i] - 1;
        }

        out.println(ans);
    }
}