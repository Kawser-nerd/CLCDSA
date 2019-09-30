import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    Scanner in;
    PrintWriter out;

    void doit(int tnum) {
        int n = in.nextInt();
        long[] d = new long[n];
        long[] l = new long[n];
        for (int i = 0; i < n; ++i) {
            d[i] = in.nextLong();
            l[i] = in.nextLong();
        }
        long D = in.nextLong();
        long[] ans = new long[n];
        ans[0] = d[0];
        boolean ok = false;
        for (int i = 1; i < n; ++i) ans[i] = -1;
        for (int i = 0; i < n; ++i) {
            if (D - d[i] <= ans[i]) ok = true;
            for (int j = i + 1; j < n; ++j) {
                if ((d[j] - d[i]) <= ans[i]) {
                    long attempt = Math.min(l[j], d[j] - d[i]);
                    if (ans[j] == -1) ans[j] = attempt;
                    if (ans[j] < attempt) ans[j] = attempt;
                }
            }
        }
        out.println("Case #" + tnum + ": " + (ok ? "YES" : "NO"));
        System.err.println("Case #" + tnum + ": " + (ok ? "YES" : "NO"));
    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("A-large.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new A().doit();
    }
}
