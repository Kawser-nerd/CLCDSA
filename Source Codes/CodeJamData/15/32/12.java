import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public int[] pi(String s) {
        int[] pi = new int[s.length()];
        for (int i = 1; i < pi.length; i++) {
            int j = pi[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = pi[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    public void solve() throws IOException {
        int k = nextInt();
        int l = nextInt();
        int s = nextInt();
        String string = nextToken();

        int[] letters = new int[26];
        for (int i = 0; i < string.length(); i++) {
            letters[string.charAt(i) - 'A']++;
        }

        string = nextToken();

        int[] pi = pi(string);
        int[][] kmp = new int[l + 1][26];
        for (int i = 0; i <= pi.length; i++) {
            for (int c = 0; c < 26; c++) {
                int j = i == pi.length ? pi[pi.length - 1] : i;
                while (j > 0 && c != (string.charAt(j) - 'A')) {
                    j = pi[j - 1];
                }
                if (c == string.charAt(j) - 'A') {
                    j++;
                }
                kmp[i][c] = j;
            }
        }

        double[][] ans = new double[s + 1][l + 1];
        ans[0][0] = 1;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j <= l; j++) {
                for (int next = 0; next < 26; next++) {
                    ans[i + 1][kmp[j][next]] += 1. * letters[next] / k * ans[i][j];
                }
            }
        }

        double res = 0;
        for (int i = 0; i < ans.length; i++) {
            res -= ans[i][l];
        }

        int pos = 0;
        for (int i = 0; i < s; i++) {
            int mc = -1;
            for (int c = 0; c < 26; c++) {
                if (letters[c] > 0 && (mc == -1 || kmp[pos][c] > kmp[pos][mc])) {
                    mc = c;
                }
            }
            pos = kmp[pos][mc];
            if (pos == l) {
                res++;
            }
        }

        out.println(res);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print(String.format("Case #%d: ", i + 1));
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
