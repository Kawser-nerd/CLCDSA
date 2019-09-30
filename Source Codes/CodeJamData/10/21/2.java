package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.logging.Handler;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve(in));
        }
        out.close();
    }

    private int solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        in.nextLine();
        Set<String> dir = new HashSet<String>();
        for (int i = 0; i < n; i++) {
            String s = in.nextLine();
            dir.add(s);
        }
        int st = dir.size();
        for (int i = 0; i < m; i++) {
            String s = in.nextLine();
            int j = 0;
            while ((j = s.indexOf("/", j + 1)) >= 0) {
                dir.add(s.substring(0, j));
            }
            dir.add(s);
        }
        return dir.size() - st;
    }
}