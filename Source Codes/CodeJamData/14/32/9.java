import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String carSet(String q) {
        StringBuffer a = new StringBuffer("");
        for (int i = 0; i < q.length(); i++) {
            if (i == 0 || q.charAt(i) != q.charAt(i - 1)) a.append(q.charAt(i));
        }
        return a.toString();
    }

    class Dsu {
        int[] dsu = new int[26];
        int[] rank = new int[26];
        Dsu() {
            for (int i = 0; i < 26; i++) dsu[i] = i;
        }
        int gett(int q) {
            if (dsu[q] == q) return q;
            return dsu[q] = gett(dsu[q]);
        }
        boolean uni(int q, int w) {
            q = gett(q);
            w = gett(w);
            if (q == w) return false;
            dsu[q] = w;
            rank[w]++;
            return true;
        }
        int count() {
            int res = 0;
            for (int i = 0; i < 26; i++) {
                if (dsu[i] == i && rank[i] > 0) res++;
            }
            return res;
        }
    }

    final long modd = 1000000007;

    void solve() throws IOException {
        int n = nextInt();
        String[] a = new String[n];
        int[] bgn = new int[26];
        int[] end = new int[26];
        int[] mid = new int[26];
        int[] onl = new int[26];
        boolean ans = true;
        int big = n;
        Dsu dsu = new Dsu();
        for (int i = 0; i < n; i++) {
            a[i] = carSet(nextToken());
            for (int j = 0; j < a[i].length(); j++) {
                int c = a[i].charAt(j) - 'a';
                if (a[i].length() == 1) {
                    if (mid[c] > 0) ans = false;
                    onl[c]++;
                    big--;
                } else if (j == 0) {
                    if (bgn[c] > 0 || mid[c] > 0) ans = false;
                    bgn[c]++;
                } else if (j == a[i].length() - 1) {
                    if (end[c] > 0 || mid[c] > 0) ans = false;
                    end[c]++;
                } else {
                    if (bgn[c] > 0 || mid[c] > 0 || end[c] > 0 || onl[c] > 0) ans = false;
                    mid[c]++;
                }
            }
            int b = a[i].charAt(0) - 'a';
            int e = a[i].charAt(a[i].length() - 1) - 'a';
            if (a[i].length() > 1) {
                if (!dsu.uni(b, e)) {
                    ans = false;
                }
            }
        }
        if (ans) {
            int cp = dsu.count();
            long res = 1;
            for (int i = 1; i <= cp; i++) res = (res * i) % modd;
            for (int i = 0; i < 26; i++) {
                if (onl[i] > 0) {
                    long tm = 1;
                    for (int j = 1; j <= onl[i]; j++) tm = (tm * j) % modd;
                    res = (res * tm) % modd;
                    if (bgn[i] == 0 && end[i] == 0) {
                        res = (res * (cp + 1)) % modd;
                        cp++;
                    }
                }
            }
            out.println(res);
        } else {
            out.println(0);
        }
    }

    void run() {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
            //in = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            Locale.setDefault(Locale.UK);
            int tt = nextInt();
            for (int t = 1; t <= tt; t++) {
                out.print("Case #" + t + ": ");
                solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    public static void main(String Args[]) {
        new Solution().run();
    }
}