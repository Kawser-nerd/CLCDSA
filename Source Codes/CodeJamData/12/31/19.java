import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Diamond implements Runnable {
    final Scanner in;
    final PrintWriter out;

    public Diamond() throws FileNotFoundException {
        out = new PrintWriter(getClass().getName().toLowerCase() + ".out");
        in = new Scanner(new File(getClass().getName().toLowerCase() + ".in"));
    }

    public static void main(String[] args) {
        try {
            new Diamond().run();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        int tests = in.nextInt();
        in.nextLine();
        for (int testcase = 1; testcase <= tests; testcase++) {
            int n = in.nextInt();
            List<List<Integer>> edges = new ArrayList<List<Integer>>();
            for (int i = 0; i < n; i++) {
                List<Integer> cur = new ArrayList<Integer>();
                int mi = in.nextInt();
                for (int x = 0; x < mi; x++) {
                    cur.add(in.nextInt() - 1);
                }
                edges.add(cur);
            }

            boolean path = false;
            for (int st = 0; st < n; st++) {
                Queue<Integer> q = new ArrayDeque<Integer>();
                Set<Integer> v = new HashSet<Integer>();
                v.add(st);
                for (q.offer(st); !q.isEmpty(); q.poll()) {
                    int c = q.peek();
                    for (int d : edges.get(c)) {
                        if (v.contains(d)) {
                            path = true;
                            continue;
                        }
                        v.add(d);
                        q.offer(d);
                    }
                }
            }
            out.println("Case #" + testcase + ": " + (path ? "Yes" : "No"));
        }


        out.close();
        in.close();
    }
}
