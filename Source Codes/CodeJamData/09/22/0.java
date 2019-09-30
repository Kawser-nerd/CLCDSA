import java.util.*;
import java.math.*;
import java.io.*;

class B implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new File("B-large.out"));

        int testn = in.nextInt();
        for (int test = 0; test < testn; test++) {
            char[] a = in.next().toCharArray();
            int n = a.length;
            int i = a.length - 1;
            while (i > 0 && a[i - 1] >= a[i]) {
                i--;
            }
            if (i == 0) {
                char[] b = new char[n + 1];
                System.arraycopy(a, 0, b, 0, n);
                b[n] = '0';
                Arrays.sort(b);
                a = b;
                for (int j = 0; j <= n; j++) {
                    if (a[j] != '0') {
                        char t = a[0]; a[0] = a[j]; a[j] = t;
                        break;
                    }
                }
            } else {
                i--;
                System.err.println(Arrays.toString(a));
                for (int j = n - 1; j > i; j--) {
                    if (a[j] > a[i]) {
                        char t = a[i]; a[i] = a[j]; a[j] = t;
                        break;
                    }
                }
                System.err.println(Arrays.toString(a));
                Arrays.sort(a, i + 1, a.length);
                System.err.println(Arrays.toString(a));
            }

            System.err.println(new String(a));
            out.println("Case #" + (test + 1) + ": " + new String(a)); 
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        new Thread(new B()).start();
    }
}