import java.util.Scanner;

public class Main {
    static final long MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt(), w = sc.nextInt(), k = sc.nextInt();
        long[][] dp = new long[h + 1][w + 2];
        long[][] table = calcTable(w);
        dp[0][1] = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 1; j <= w; j++) {
                dp[i + 1][j] = dp[i][j] * table[j - 1][0] % MOD
                        + dp[i][j - 1] * table[j - 1][1] % MOD
                        + dp[i][j + 1] * table[j - 1][2] % MOD;
                dp[i + 1][j] %= MOD;
            }
        }
//        for (long[] arr : dp) {
//            for (long l : arr) {
//                System.out.print(l + " ");
//            }
//            System.out.println();
//        }
        System.out.println(dp[h][k]);
    }

    private static long[][] calcTable(int w) {
        long[][] arr = new long[w][3];
        int kukan = w-1;
        for (int i = 0; i < w; i++) {
            loop:
            for (int j = 0; j < (1L<<kukan); j++) {
                verify:
                for (int k = 0; k < kukan; k++) {
                    if(k==0) continue verify;
                    if(((j>>k) & 1) == 1 && ((j>>k-1) & 1) == 1) continue loop;
                }

                if(check(i-1,j,kukan,true) && check(i,j,kukan,true)) {
                    arr[i][0]++;
                }
                if(check(i-2,j,kukan,true) && check(i-1,j,kukan,false) && check(i,j,kukan,true)) {
                    arr[i][1]++;
                }
                if(check(i-1,j,kukan ,true) && check(i,j,kukan,false) && check(i+1,j,kukan,true)) {
                    arr[i][2]++;
                }
            }
        }
        return arr;
    }

    private static boolean check(int slide, int num, int kukan, boolean isZero) {
        if(slide < 0 || slide >= kukan) {
            return true;
        }

        return  (num>>slide & 1) == (isZero ? 0 : 1);
    }
}