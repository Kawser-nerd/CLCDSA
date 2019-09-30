import java.io.*;
import java.util.StringTokenizer;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Arrays;

/**
 * @author Ivan Romanov
 */
public class B {
    private static final String IMPOSSIBLE = "IMPOSSIBLE";

    private static class Seq implements Comparable<Seq> {

        private static int time = 0;

        int[] idx, color;

        boolean satisfied = false;

        int t;

        public Seq(int size) {
            idx = new int[size];
            color = new int[size];
            t = time++;
        }

        public int size() {
            return idx.length;
        }

        public int compareTo(Seq that) {
            if (this.idx.length < that.idx.length) return -1;
            if (this.idx.length > that.idx.length) return 1;
            if (this.t < that.t) return -1;
            if (this.t > that.t) return 1;
            if (this != that) {
                throw null;
            }
            return 0;
        }
    }

    private String solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        SortedSet<Seq> a = new TreeSet<Seq>();
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for (int i = 0; i < m; i++) {
            int t = nextInt();
            Seq s = new Seq(t);
            for (int j = 0; j < t; j++) {
                s.idx[j] = nextInt() - 1;
                s.color[j] = nextInt();
            }
            a.add(s);
        }
        while (!a.isEmpty()) {
            Seq s = a.first();
            if (s.size() > 1) {
                break;
            }
            if (s.size() == 1) {
                int paint = s.idx[0];
                if (color[paint] != -1) {
                    if (color[paint] != s.color[0]) {
                        return IMPOSSIBLE;
                    }
                }
                color[paint] = s.color[0];

                SortedSet<Seq> b = new TreeSet<Seq>();
                for (Seq item : a) {
                    int cnt = 0;
                    for (int i = 0; i < item.idx.length; i++) {
                        if (item.idx[i] != paint) {
                            cnt++;
                        } else {
                            item.satisfied |= item.color[i] == color[paint];
                        }
                    }
                    if (cnt > 0) {
                        Seq newItem = new Seq(cnt);
                        cnt = 0;
                        for (int i = 0; i < item.size(); i++) {
                            if (item.idx[i] != paint) {
                                newItem.idx[cnt] = item.idx[i];
                                newItem.color[cnt] = item.color[i];
                                cnt++;
                            }
                        }
                        if (!item.satisfied) {
                            b.add(newItem);
                        }
                    } else if (!item.satisfied) {
                        return IMPOSSIBLE;
                    }
                }
                a = b;
            } else {
                a.remove(s);
                System.err.println("??? zero-sized element");
            }
        }
        String ans = "";
        for (int x : color) {
            if (x == -1) {
                x = 0;
            }
            if (ans.length() > 0) {
                ans += " ";
            }
            ans += x;
        }
        return ans;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter writer = new PrintWriter(new File("B-large.out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}