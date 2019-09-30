import java.util.Scanner;

public class Main {
    private static final long MOD = 1000000007L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            char[][] t = new char[n][2];
            for (int i = 0; i < 2; i++) {
                String s = sc.next();
                for (int j = 0; j < n; j++) {
                    t[j][i] = s.charAt(j);
                }
            }
            System.out.println(solve(n, t));
        }
    }

    private static long solve(int n, char[][] t) {
        long[][][] dp = new long[n + 1][4][4];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ( t[0][0] == t[0][1] ) {
                    if ( i == j ) {
                        dp[0][i][j] = 1;
                    }
                } else {
                    if ( i != j ) {
                        dp[0][i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if ( dp[i][j][k] == 0 ) {
                        continue;
                    }

                    for (int nj = 0; nj < 3; nj++) {
                        for (int nk = 0; nk < 3; nk++) {
                            if ( t[i][0] == t[i + 1][0] ) {
                                if ( j == nj && k == nk ) {
                                    dp[i + 1][nj][nk] += dp[i][j][k];
                                    dp[i + 1][nj][nk] %= MOD;
                                }
                            } else {
                                if ( j != nj && k != nk ) {
                                    if ( t[i + 1][0] == t[i + 1][1] && nj == nk ||
                                        t[i + 1][0] != t[i + 1][1] && nj != nk ) {
                                        dp[i + 1][nj][nk] += dp[i][j][k];
                                        dp[i + 1][nj][nk] %= MOD;
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }

        long ans = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ans += dp[n - 1][j][k];
                ans %= MOD;
            }
        }

        return ans;
    }
}