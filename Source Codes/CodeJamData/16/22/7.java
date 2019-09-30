
import java.io.*;
import java.util.StringTokenizer;

public class B {

    long res;
    String r1, r2;

    private String solveTest() throws IOException {
        String s1 = next();
        String s2 = next();

        calc(s1, s2, false);
        long bestRes = res;
        String bestR1 = r1;
        String bestR2 = r2;

        calc(s2, s1, true);
        if (res < bestRes ||
                res == bestRes && r2.compareTo(bestR1) < 0 ||
                res == bestRes && r2.compareTo(bestR1) == 0 && r1.compareTo(bestR2) < 0) {
            bestRes = res;
            bestR1 = r2;
            bestR2 = r1;
        }

//        s1 = s1.replaceAll("\\?", ".");
//        s2 = s2.replaceAll("\\?", ".");
//        while (s1.length() < 3) s1 = '0' + s1;
//        while (s2.length() < 3) s2 = '0' + s2;
//
//        int res2 = Integer.MAX_VALUE;
//        String r1 = "";
//        String r2 = "";
//        for (int i = 1000; i <= 1999; i++) {
//            String s = ("" + i).substring(1);
//            if (!s.matches(s1)) continue;
//            for (int j = 1000; j <= 1999; j++) {
//                String t = ("" + j).substring(1);
//                if (!t.matches(s2)) continue;
//                int d = Math.abs(i - j);
//                if (d < res2) {
//                    res2 = d;
//                    r1 = s.substring(3 - bestR1.length());
//                    r2 = t.substring(3 - bestR1.length());
//                }
////                if (d < bestRes) {
////                    System.out.println("!!!");
////                    System.out.println(s + " " + t);
////                }
//            }
//        }
//        if (!(r1 + " " + r2).equals(bestR1 + " " + bestR2)) {
//            System.out.println("!!!" + (s1 + " " + s2) + ": " + (r1 + " " + r2) + " --- " + (bestR1 + " " + bestR2));
//        }
//        if (res2 != bestRes) System.out.println(bestRes + " " + res2);

        return bestR1 + " " + bestR2;
    }

    private void calc(String s1, String s2, boolean b) { // s1 >= s2
        int n = s1.length();
        long[] rr = new long[n];
        long d = 0;
        long[] p10 = new long[n];
        p10[0] = 1;
        for (int i = 1; i < n; i++) {
            p10[i] = p10[i - 1] * 10;
        }
        for (int i = n - 1; i >= 0; i--) {
            rr[i] = d;
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            d += p10[n - 1 - i] * ((c1 == '?' ? 0 : (c1 - '0')) - (c2 == '?' ? 9 : (c2 - '0')));
        }
        res = Long.MAX_VALUE;

        String suf1 = s1.replaceAll("\\?", "0");
        String suf2 = s2.replaceAll("\\?", "9");

        String pref1 = "";
        String pref2 = "";

        boolean ok = true;
        for (int i = 0; i < n; i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if (c1 != '?' && c2 != '?' && c1 > c2 ||
                    c1 == '?' && c2 == '?' ||
                    c1 == '?' && c2 != '9' ||
                    c2 == '?' && c1 != '0') {
                char cc1 = c1;
                char cc2 = c2;
                if (c1 == '?' && c2 == '?') {
                    cc1 = '1';
                    cc2 = '0';
                } else if (c1 == '?') {
                    cc1 = (char) (c2 + 1);
                } else if (c2 == '?') {
                    cc2 = (char) (c1 - 1);
                }
                int dd = cc1 - cc2;
                long s = p10[n - 1 - i] * dd + rr[i];
                String nr1 = pref1 + cc1 + suf1.substring(i + 1);
                String nr2 = pref2 + cc2 + suf2.substring(i + 1);
                if (s < res) {
                    res = s;
                    r1 = nr1;
                    r2 = nr2;
                } else if (s == res) {
                    if (b && nr2.compareTo(r2) < 0) {
                        r1 = nr1;
                        r2 = nr2;
                    }
                    if (!b && nr1.compareTo(r1) < 0) {
                        r1 = nr1;
                        r2 = nr2;
                    }
                }
            }
            if (c1 == c2 || c1 == '?' || c2 == '?') {
                char cc1 = c1;
                char cc2 = c2;
                if (c1 == '?' && c2 == '?') {
                    cc1 = '0';
                    cc2 = '0';
                } else if (c1 == '?') {
                    cc1 = c2;
                } else if (c2 == '?') {
                    cc2 = c1;
                }
                pref1 += cc1;
                pref2 += cc2;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            res = 0;
            r1 = pref1;
            r2 = pref2;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String res = solveTest();
            System.out.println("Case #" + (i + 1) + ": " + res);
            out.println("Case #" + (i + 1) + ": " + res);
        }
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }

    private void run() throws FileNotFoundException {
        br = new BufferedReader(new FileReader(this.getClass().getSimpleName().substring(0, 1) + ".in"));
        out = new PrintWriter(this.getClass().getSimpleName().substring(0, 1) + ".out");
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

}