/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
?????????????????????????ex.-1/2=0??????>k??????????????????
???>=k???????????????
toLowerCase()???????????????????????????
ArrayDeque??pop?push?Stack????????
*/
//?????Ctrl+D
import java.util.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int[][][][] dp = new int[n][4][4][4];
        int mod = 1000000007;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if ((j == 0 && k == 2 && l == 1) || (j == 0 && k == 1 && l == 2) || (j == 2 && k == 0 && l == 1))
                        continue;
                    dp[2][j][k][l] = 1;
                }
            }
        }
        for (int i = 2; i < n - 1; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        for (int m = 0; m < 4; m++) {
                            if (check(j, k, l, m))
                                dp[i + 1][k][l][m] = (dp[i + 1][k][l][m] + dp[i][j][k][l]) % mod;
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    ans = (ans + dp[n - 1][i][j][k]) % mod;
                }
            }
        }
        out.println(ans);
    }

    static boolean check(int j, int k, int l, int m) {
        int a = 0, c = 1, g = 2, t = 3;
        if ((k == a && l == g && m == c) || (k == a && l == c && m == g) || (k == g && l == a && m == c)) return false;
        if ((j == a && k == g && l == c) || (j == g && k == a && l == c) || (j == a && k == c && l == g)) return false;
        if ((j == a && l == g && m == c) || (j == a && k == g && m == c)) return false;
        return true;
    }
}