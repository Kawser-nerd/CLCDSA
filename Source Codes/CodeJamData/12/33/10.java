import java.io.*;
import java.util.*;

public class G_3 {

    public static void main(String[] args) throws Exception {
        G_3 instance = new G_3();
        instance.func();
    }

    PrintWriter bw;
    long[] a, A;
    long[] b, B;
    long[][] dp;
    int N, M;

    long find_left(int n, int m, int dir, long left) {
        if (n >= N || m >= M) {
            return 0;
        }
        long max = 0;
        long tmp;
        long sum = 0;
        if (dir == 1) {
            if (left == 0) {
                return find(n + 1, m);
            }
            for (int i = m; i < M; ++i) {
                if (A[n] == B[i]) {
                    if (left > b[i]) {
                        // System.out.println(n + " " + m + " " + left + " " + max);
                        left -= b[i];
                        sum += b[i];
                        tmp = find(n + 1, i + 1) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                    } else {
                        sum += left;
                        left = b[i] - left;
                        tmp = find(n + 1, i + 1) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                        tmp = find_left(n + 1, i, 2, left) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                        // System.out.println(n + " " + i + " " + left + " " + dir + " " + max);
                        break;
                    }
                }
            }
        } else if (dir == 2) {
            if (left == 0) {
                return find(n, m + 1);
            }
            for (int i = n; i < N; ++i) {
                if (A[i] == B[m]) {
                    if (left > a[i]) {
                        left -= a[i];
                        sum += a[i];
                        tmp = find(i + 1, m + 1) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                    } else {
                        sum += left;
                        left = a[i] - left;
                        tmp = find(i + 1, m + 1) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                        tmp = find_left(i, m + 1, 1, left) + sum;
                        if (tmp > max) {
                            max = tmp;
                        }
                        // System.out.println(i + " " + m + " " + left + " " + dir + " " + max);
                        break;
                    }
                }
            }
        }
        return max;
    }

    long find(int n, int m) {
        if (n >= N || m >= M) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        long max = 0;
        long tmp;
        if (A[n] == B[m]) {
            tmp = Math.max(find(n, m + 1), find(n + 1, m));
            if (tmp > max) {
                max = tmp;
            }
            if (a[n] < b[m]) {
                tmp = find(n + 1, m + 1) + a[n];
                if (tmp > max) {
                    max = tmp;
                }
                tmp = find_left(n + 1, m, 2, b[m] - a[n]) + a[n];
                if (tmp > max) {
                    max = tmp;
                }
                // System.out.println(n + " " + m + " " + max);
            } else {
                tmp = find(n + 1, m + 1) + b[m];
                if (tmp > max) {
                    max = tmp;
                }
                tmp = find_left(n, m + 1, 1, a[n] - b[m]) + b[m];
                if (tmp > max) {
                    max = tmp;
                }
                // System.out.println(n + " " + m + " " + max);
                // System.out.println(max);
            }
            dp[n][m] = max;
        } else {
            dp[n][m] = Math.max(find(n, m + 1), find(n + 1, m));
        }
        return dp[n][m];
    }

    public void func() throws Exception {
        bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int i = 0; i < T; i++) {

            N = scan.nextInt();
            M = scan.nextInt();
            a = new long[N];
            A = new long[N];
            b = new long[M];
            B = new long[M];
            for (int j = 0; j < N; ++j) {
                a[j] = scan.nextLong();
                A[j] = scan.nextLong();
            }
            for (int j = 0; j < M; ++j) {
                b[j] = scan.nextLong();
                B[j] = scan.nextLong();
            }
            dp = new long[N][M];
            for (int j = 0; j < N; ++j) {
                Arrays.fill(dp[j], -1);
            }
            long ret = find(0, 0);

            for (int j = 0; j < N; ++j) {
                //System.out.println(Arrays.toString(dp[j]));
                // Arrays.fill(dp[j], -1);
            }

            print(String.format("Case #%d: %d", (i + 1), ret));
            print("\n");
        }
        bw.flush();
        bw.close();
    }

    void print(String s) {
        System.out.print(s);
        bw.write(s);
    }
}
