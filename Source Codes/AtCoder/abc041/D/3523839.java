import java.util.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[][] faster = new boolean[n][n];
        for(int i = 0; i < m; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            faster[x][y] = true;
        }

        long[] bitDp = new long[1 << n];
        bitDp[0] = 1;
        for(int i = 0; i < (1 << n) - 1; i++) {
            if (bitDp[i] == 0) continue;

            for(int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 0) { // ????i?j??????????
                    int k;
                    for(k = 0; k < n; k++) {
                        if (((i >> k) & 1) == 1 && faster[j][k]) { // ????i?k????????j?k??
                            break;
                        }
                    }
                    if (k == n) {
                        bitDp[i | 1 << j] += bitDp[i];
                    }
                }
            }
        }
        System.out.println(bitDp[(1 << n) - 1]);
    }

}