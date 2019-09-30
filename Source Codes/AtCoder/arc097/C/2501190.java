import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    private BufferedReader in;
    private StringTokenizer tok;
    private PrintWriter out;

    //------------------------------------------------------------------------------
    public static void main(String[] args) {
        new Main().run();
    }

    static final int INF = (int) 1e9;

    private void solve() throws IOException {
        int n = readInt();
        char[] color = new char[2 * n];
        int[] number = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            color[i] = readString().charAt(0);
            number[i] = readInt() - 1;
        }

        int[][] black = new int[n][2 * n];
        for (int val = 0; val < n; val++) {
            int cnt = 0;
            for (int i = 2 * n - 1; i >= 0; i--) {
                if (number[i] >= val && color[i] == 'B') {
                    cnt++;
                }
                black[val][i] = cnt;
            }
        }

        int[][] white = new int[n][2 * n];
        for (int val = 0; val < n; val++) {
            int cnt = 0;
            for (int i = 2 * n - 1; i >= 0; i--) {
                if (number[i] >= val && color[i] == 'W') {
                    cnt++;
                }
                white[val][i] = cnt;
            }
        }

        int[] posBlack = new int[n];
        int[] posWhite = new int[n];
        for (int i = 0; i < 2 * n; i++) {
            if (color[i] == 'B') {
                posBlack[number[i]] = i;
            } else {
                posWhite[number[i]] = i;
            }
        }

        int[][] dp = new int[n + 1][n + 1];
        for (int[] arr : dp) Arrays.fill(arr, INF);
        dp[0][0] = 0;
        for (int w = 0; w <= n; w++) {
            for (int b = 0; b <= n; b++) {
                if (w == n && b == n) {
                    continue;
                }
                if (w < n) {
                    int pos = posWhite[w];
                    int whiteToRight = white[w][pos] - 1;
                    int blackToRight = b == n ? 0 : black[b][pos];
                    int whiteToLeft = n - whiteToRight - w - 1;
                    int blackToLeft = n - blackToRight - b;
                    check(whiteToLeft, n - 1);
                    check(blackToLeft, n);
                    dp[w + 1][b] = Math.min(dp[w + 1][b], dp[w][b] + whiteToLeft + blackToLeft);
                }
                if (b < n) {
                    int pos = posBlack[b];
                    int whiteToRight = w == n ? 0 : white[w][pos];
                    int blackToRight = black[b][pos] - 1;
                    int whiteToLeft = n - whiteToRight - w;
                    int blackToLeft = n - blackToRight - b - 1;
                    check(whiteToLeft, n);
                    check(blackToLeft, n - 1);
                    dp[w][b + 1] = Math.min(dp[w][b + 1], dp[w][b] + whiteToLeft + blackToLeft);
                }
            }
        }
        out.println(dp[n][n]);
    }

    private void check(int val, int max) {
        if (val < 0 || val > max) {
            throw new AssertionError();
        }
    }

    private void run() {
        try {
            initIO();
            solve();
            in.close();
            out.close();
        } catch (Throwable e) {
            throw new RuntimeException(e);
        }
    }

    private void initIO() throws IOException {
        try {
            in = new BufferedReader(new FileReader(new File("input.txt")));
            out = new PrintWriter(new File("output.txt"));
        } catch (Exception e) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    private String readString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}