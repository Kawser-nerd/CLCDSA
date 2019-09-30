import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    Scanner in;
    PrintWriter out;

    int[] x;
    int[] ans;
    int n;
    boolean ok;

    void getH(int from, int to) {
        if (!ok) return;
        if (from == to) {
            ans[from] = 0;
            return;
        }
        for (int i = from; i < to; ++i) if (x[i] > to) ok = false;
        if (!ok) return;
        int peak = x[from];
        getH(from + 1, peak);
        if (!ok) return;
        ans[from] = 0;
        for (int i = from + 1; i <= peak; ++i) ans[i] -= (peak - i);
        getH(peak, to);
    }

    void doit(int tnum) {
        System.err.println(tnum);
        ok = true;
        n = in.nextInt();
        x = new int[n - 1];
        ans = new int[n];
        for (int i = 0; i < (n - 1); ++i) x[i] = in.nextInt() - 1;
        getH(0, n - 1);
        out.print("Case #" + tnum + ":");
        if (!ok) {
            out.println(" Impossible");
            return;
        }
        int OMIN = 0;
        for (int i = 0; i < n; ++i) if (OMIN > ans[i]) OMIN = ans[i];
        for (int i = 0; i < n; ++i) out.print(" " + (ans[i] - OMIN + 1));
        out.println();
    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("C-large.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new B().doit();
    }
}
