import sun.java2d.pipe.OutlineTextRenderer;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    private static final int MAX = 20000;

    private String solve(Scanner in) {
        int n = in.nextInt();
        if (n == 0) {
            return "0";
        }
        int[] a = new int[MAX];
        for (int i = 0; i < n; i++) {
            a[in.nextInt() - 1]++;
        }
        int l = 1;
        int r = n + 1;
        main: while (r > l + 1) {
            int m = (l + r) / 2;
            int[] aa = a.clone();
            int[] b = new int[MAX + 1];
            for (int i = 0; i < MAX; i++) {
                while (aa[i] > 0) {
                    if (i > 0 && b[i - 1] > 0) {
                        b[i - 1]--;
                        b[i]++;
                        aa[i]--;
                    } else {
                        boolean ok = true;
                        for (int j = i; j < i + m; j++) {
                            if (aa[j] == 0) ok = false;
                            aa[j]--;
                        }
                        if (!ok) {
                            r = m;
                            continue main;
                        }
                        b[i + m - 1]++;
                    }
                }
            }
            l = m;
        }
        return "" + l;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}