package codejam.round1c_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class MainA {

    static char[] mapping = new char[256];
    static List<Set<Integer>> defs;
    
    public static void main(String[] args) throws Exception {

        String f = "/home/floris/dev/java/Test/src/codejam/round1c_2012/A-large.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        for (int i=1; T-- > 0; i++) {
            defs = new ArrayList<Set<Integer>>();
            int classCount = sc.nextInt();
            for (int j = 0; j < classCount; j++) {
                Set<Integer> cur = new HashSet<Integer>();
                int ic = sc.nextInt();
                for (int k = 0; k < ic; k++) cur.add(sc.nextInt()-1);
                defs.add(cur);
            }
            System.out.printf("Case #%d: %s%n", i, solve());
        }
    }

    private static String solve() {
        for (int i = 0; i < defs.size(); i++) {
            List<Integer> contained = new ArrayList<Integer>();
            Deque<Integer> d = new ArrayDeque();
            d.addAll(defs.get(i));
            contained.addAll(defs.get(i));
            contained.add(i);
            while (!d.isEmpty()) {
                int v = d.remove();
                for (int k : defs.get(v)) {
                    if (contained.contains(k)) return "Yes";
                    d.add(k);
                    contained.add(k);
                }
            }
        }
        return "No";
    }
}
