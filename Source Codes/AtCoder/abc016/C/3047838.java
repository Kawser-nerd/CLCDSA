import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            List<Set<Integer>> friends = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                friends.add(new HashSet<>());
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                friends.get(a).add(b);
                friends.get(b).add(a);
            }
            for (int i = 0; i < n; i++) {
                Set<Integer> friend = friends.get(i);
                Set<Integer> ff = new HashSet<>();
                for (int f : friend) {
                    ff.addAll(friends.get(f));
                }
                ff.removeAll(friend);
                ff.remove(i);
                out.println(ff.size());
            }
        }

    }
}