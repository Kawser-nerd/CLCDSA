import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class A {
    public void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter("A-large.out");

        int testN = in.nextInt();
        for (int test = 1; test <= testN; test++) {
            out.print("Case #" + test + ": ");

            int n = in.nextInt();
            int m = in.nextInt();
            String[] exists = new String[n];
            String[] create = new String[m];
            Set<String> ex = new HashSet<String>();
            for (int i = 0; i < n; i++) {
                exists[i] = in.next();
                String[] t = exists[i].split("/");
                String r = "";
                for (int j = 1; j < t.length; j++) {
                    r = r + "/" + t[j];
                    ex.add(r);
                }
            }
            Set<String> need = new TreeSet<String>();
            for (int i = 0; i < m; i++) {
                create[i] = in.next();
                String[] t = create[i].split("/");
                String r = "";
                for (int j = 1; j < t.length; j++) {
                    r = r + "/" + t[j];
                    need.add(r);
                }
            }

            int res = 0;
            for (String s : need) {
                if (!ex.contains(s)) {
                    res++;
                    ex.add(s);
                }
            }

            out.println(res);
        }

        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().solve();
    }
}
