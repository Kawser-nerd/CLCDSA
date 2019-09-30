import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    public static double EPS = 0.000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public static void expandRow(char[] row) {
        char cur = '?';
        for (int i = 0; i < C; i++) {
            if (row[i] != '?') {
                cur = row[i];
                break;
            }
        }
        if (cur == '?') return;
        for (int i = 0; i < C; i++) {
            if (row[i] != '?' && row[i] != cur) {
                cur = row[i];
            } else {
                row[i] = cur;
            }
        }
    }

    public static void printCake(char[][] cake) {
        for (int i = 0; i < R; i++) {
            String s = "";
            for (int j = 0; j < C; j++) {
                s += cake[i][j];
            }
            print(s);
        }
    }

    public static int R;
    public static int C;

    public static void main(String[] args) throws IOException {
        // br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            R = nextInt();
            C = nextInt();

            char[][] cake = new char[R][C];
            for (int i = 0; i < R; i++) {
                cake[i] = nextToken().toCharArray();
                expandRow(cake[i]);
            }

            // Fill in empty rows from above
            for (int i = 1; i < R; i++) {
                if (cake[i][0] == '?') {
                    cake[i] = cake[i-1];
                }
            }

            // Fill in empty rows from below
            for (int i = R-1; i >= 0; i--) {
                if (cake[i][0] == '?') {
                    cake[i] = cake[i+1];
                }
            }

            System.out.printf("Case #%d:%n", t);
            printCake(cake);
        }
    }
}
