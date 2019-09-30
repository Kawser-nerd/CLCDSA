import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("C-small-attempt1.in"));
        PrintWriter out = new PrintWriter("C-small-attempt1.out");

        int testN = in.nextInt();

        for (int test = 1; test <= testN; test++) {
            out.print("Case #" + test + ": ");

            int c = in.nextInt();
            int[] a = new int[4000000];
            TreeSet<Integer> pos = new TreeSet<Integer>();
            for (int i = 0; i < c; i++) {
                int p = in.nextInt() + 2000000;
                int v = in.nextInt();
                a[p] += v;
                if (v > 1) {
                    pos.add(p);
                }
            }

            int r = 0;
            while (pos.size() != 0) {
                int q = pos.pollFirst();
                a[q] -= 2;
                a[q - 1]++;
                if (a[q - 1] == 2) {
                    pos.add(q - 1);
                }
                a[q + 1]++;
                if (a[q + 1] == 2) {
                    pos.add(q + 1);
                }
                if (a[q] >= 2) {
                    pos.add(q);
                }
                r++;
            }

            out.println(r);
        }

        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().solve();
    }
}