import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class A {
    private boolean go(int index, BitSet[] sets, List<List<Integer>> deps, Boolean[] cache) {
        if (cache[index] != null) {
            return cache[index];
        }
        boolean ans = false;
        for (int dep : deps.get(index)) {
            go(dep, sets, deps, cache);
            ans |= sets[index].intersects(sets[dep]);
            sets[index].or(sets[dep]);
        }
        sets[index].set(index);
        return cache[index] = ans;
    }

    public void run(Scanner in, PrintWriter out, int nCase) {
        int n = in.nextInt();
        BitSet[] sets = new BitSet[n];
        List<List<Integer>> deps = new ArrayList<List<Integer>>();
        for (int i = 0; i < n; ++i) {
            sets[i] = new BitSet();
            deps.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < n; ++i) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; ++j) {
                deps.get(i).add(in.nextInt() - 1);
            }
        }

        Boolean[] counted = new Boolean[n];

        boolean ans = false;
        for (int i = 0; i < n && !ans; ++i) {
            ans = go(i, sets, deps, counted);
        }
        out.printf("Case #%d: %s%n", nCase, ans ? "Yes" : "No");
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = A.class.getSimpleName().toLowerCase();

        Scanner in = new Scanner(new File(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");

        int nCases = in.nextInt();

        for (int i = 1; i <= nCases; ++i) {
            new A().run(in, out, i);
        }

        out.close();
        in.close();
    }
}
