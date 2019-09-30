/* Genrator:
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.ArrayList;
import java.util.Scanner;


public class Prob1 implements Runnable {

    Scanner sc;
    PrintWriter pw;

    void err(Object o) {
        System.err.println(o.toString());
    }
    void err2(Object o) {
        System.err.print(o.toString());
    }
    void out(Object o) {
        pw.println(o.toString());
        err(o);
    }
    void out2(Object o) {
        pw.print(o.toString());
        err2(o);
    }
    int a[] = new int[1000];
    boolean palind(BigInteger tk) {
        String s = tk.toString();
        for (int i = 0; i < s.length() - i - 1; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
    void bct(int len, int k) {
        if (k > len - 1 - k) {
            BigInteger tk = BigInteger.ZERO;
            for (int i = 0; i < len; i++) {
                tk = tk.multiply(BigInteger.TEN).add(BigInteger.valueOf(a[i]));
            }
            BigInteger sq = tk.multiply(tk);
            if (!palind(sq)) {
                return;
            }
            out(tk + " " + sq);
            return;
        }
        int mx = 1;
        if (len == 1) {
            mx = 3;
        }
        if (k == 0 || k == len - 1 - k) {
            mx = 2;
        }
        for (int i = (k == 0 ? 1 : 0); i <= mx; i++) {
            a[k] = i;
            a[len - 1 - k] = i;
            bct(len, k + 1);
        }
    }
    public void run() {
        try {
            sc = new Scanner(new File("input.txt"));
            pw = new PrintWriter(new File("output.txt"));
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
        for (int len = 1; len <= 51; len++) {
            err(len);
            for (int i = 0; i < len; i++) {
                a[i] = -1;
            }
            bct(len, 0);
        }
        sc.close();
        pw.close();
    }
    public static void main(String[] args) {
        new Thread(new Prob1()).start();
    }
}
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.ArrayList;
import java.util.Scanner;


public class Prob2 implements Runnable {

    Scanner sc;
    PrintWriter pw;

    void err(Object o) {
        System.err.println(o.toString());
    }
    void err2(Object o) {
        System.err.print(o.toString());
    }
    void out(Object o) {
        pw.println(o.toString());
        err(o);
    }
    void out2(Object o) {
        pw.print(o.toString());
        err2(o);
    }
    BigInteger a[] = new BigInteger[10000000];
    int k = 0;
    int find(BigInteger x) {
        int l = 0;
        int r = k - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m].compareTo(x) >= 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    public void run() {
        try {
            sc = new Scanner(new File("output.txt"));
            //pw = new PrintWriter(new File("output.txt"));
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        while (sc.hasNextBigInteger()) {
            BigInteger b1 = sc.nextBigInteger();
            BigInteger b2 = sc.nextBigInteger();
          //  err(b2);
            a[k++] = b2;
        }
        sc.close();
        try {
            sc = new Scanner(new File("input.txt"));
            pw = new PrintWriter(new File("output2.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }
        int t = sc.nextInt();
        for (int ti = 0; ti < t; ti++) {
            BigInteger x = sc.nextBigInteger();
            BigInteger y = sc.nextBigInteger();
            out("Case #" + (ti + 1) + ": " + (find(y.add(BigInteger.ONE)) - find(x)));
        }
        sc.close();
        pw.close();
    }
    public static void main(String[] args) {
        new Thread(new Prob2()).start();
    }
}