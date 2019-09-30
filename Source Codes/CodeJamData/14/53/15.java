
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            a[i] = s.equals("E") ? 1 : -1;
            b[i] = in.nextInt();
        }
        boolean[] t = new boolean[2001];
        for (int i = 0; i < n; i++) {
            t[b[i]] = true;
        }
//        int[] zz = new int[2001];
//        int cc = 0;
//        for (int i = 1; i < t.length; i++) {
//            if (t[i]) {
//                cc++;
//                zz[i] = cc;
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            b[i] = zz[b[i]];
//        }
        int[] p = new int[2001];
//        int res = bt(a, b, p, 0);
//        if (true) {
//            return "" + res;
//        }
        int[] l = new int[2001];
        for (int i = 0; i < n; i++) {
            int x = b[i];
            if (x > 0) {
                if (p[x] == 1 && a[i] == 1) {
                    boolean ok = false;
                    for (int j = l[x] + 1; j < i; j++) {
                        if (a[j] == -1 && b[j] == 0) {
                            b[j] = x;
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) return "CRIME TIME";
                }
                l[x] = i;
                p[x] = a[i];
            }
        }
        p = new int[2001];
        l = new int[2001];
        for (int i = n - 1; i >= 0; i--) {
            int x = b[i];
            if (x > 0) {
                if (p[x] == -1 && a[i] == -1) {
                    boolean ok = false;
                    for (int j = l[x] - 1; j > i; j--) {
                        if (a[j] == 1 && b[j] == 0) {
                            b[j] = x;
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) return "CRIME TIME";
                }
                l[x] = i;
                p[x] = a[i];
            }
        }
        p = new int[2001];
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 1 && b[i] > 0 && p[b[i]] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (a[j] == -1 && b[j] == 0) {
                        b[j] = b[i];
                        break;
                    }
                }
            }
            p[b[i]] = a[i];
        }
        p = new int[2001];
        for (int i = 0; i < n; i++) {
            if (a[i] == -1 && b[i] > 0 && p[b[i]] == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (a[j] == 1 && b[j] == 0) {
                        b[j] = b[i];
                        break;
                    }
                }
            }
            p[b[i]] = a[i];
        }
        boolean[] z = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && b[i] == 0) {
                for (int j = i; j < n; j++) {
                    if (a[j] == -1 && b[j] == 0 && !z[j]) {
                        z[i] = true;
                        z[j] = true;
                        break;
                    }
                }
            }
        }
        p = new int[2001];
        l = new int[2001];
        for (int i = 0; i < n; i++) {
            int x = b[i];
            if (x > 0) {
                if (a[i] == -1 && p[x] == 1) {
                    for (int j = l[x] + 1; j < i; j++) {
                        if (a[j] == -1 && b[j] == 0) {
                            for (int k = j + 1; j < i; j++) {
                                if (a[j] == 1 && b[j] == 0) {
                                    b[j] = x;
                                    b[k] = x;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                l[x] = i;
                p[x] = a[i];
            }
        }
        p = new int[2001];
        for (int i = 0; i < n; i++) {
            if (b[i] != 0) {
                if (p[b[i]] != 0 && p[b[i]] != -a[i]) {
//                    System.out.println("!!!!!");
                }
                p[b[i]] = a[i];
            }
        }
        int res = 0;
        for (int i = 1; i < p.length; i++) {
            if (p[i] == 1) {
                res++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && b[i] == 0 && !z[i]) {
                res++;
            }
        }

        return "" + res;
    }

    private int bt(int[] a, int[] b, int[] p, int i) {
        if (i == a.length) {
            int res = 0;
            for (int x = 1; x < p.length; x++) {
                if (p[x] == 1) res++;
            }
            return res;
        }
        int x = b[i];
        if (x > 0) {
            int y = p[x];
            if (y == 0 || y == -a[i]) {
                p[x] = a[i];
                int res = bt(a, b, p, i + 1);
                p[x] = y;
                return res;
            } else {
                return 100000;
            }
        } else {
            int min = 100000;
            for (x = 1; x <=    a.length; x++) {
                int y = p[x];
                if (y == 0 || y == -a[i]) {
                    p[x] = a[i];
                    min = Math.min(min, bt(a, b, p, i + 1));
                    p[x] = y;
                }
            }
            return min;
        }
    }
}