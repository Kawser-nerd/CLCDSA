import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class TaskC {

    public static final int SHIFT = 250;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskC().run();
    }

    void run() throws IOException {
        br = new BufferedReader(new FileReader("C-small-attempt0.in"));
        out = new PrintWriter("output.txt");
        solve();

        out.close();
    }

    static class Tribe implements Comparable<Tribe> {
        int day, count, left, right, strength;
        int d_day, d_left, d_strength;

        Tribe(int day, int count, int left, int right, int strength, int d_day, int d_left, int d_strength) {
            this.day = day;
            this.count = count;
            this.left = left;
            this.right = right;
            this.strength = strength;
            this.d_day = d_day;
            this.d_left = d_left;
            this.d_strength = d_strength;
        }

        @Override
        public int compareTo(Tribe o) {
            return Integer.compare(day, o.day);
        }
    }

    static class Change {
        int left, right, level;

        Change(int left, int right, int level) {
            this.left = left;
            this.right = right;
            this.level = level;
        }

        public void apply(int[] array) {
            for (int i = left; i < right; i++) {
                int j = i + SHIFT;
                array[j] = Math.max(array[j], level);
            }
        }
    }

    void solve() throws IOException {
        int t = nextInt();
        for (int i = 0; i < t; i++)
            solveCase();
    }

    int testCount = 1;
    void solveCase() throws IOException {
        int n = nextInt();
        PriorityQueue<Tribe> q = new PriorityQueue<Tribe>();
        for (int i = 0; i < n; i++) {
            q.add(new Tribe(nextInt(), nextInt(), nextInt(), nextInt(), nextInt(), nextInt(), nextInt(), nextInt()));
        }

        Deque<Change> ch = new ArrayDeque<Change>();
        int lastStep = -1;

        int[] array = new int[600];
        int result = 0;
        while (!q.isEmpty()) {
            Tribe curr = q.poll();
            if (lastStep < curr.day) while (!ch.isEmpty()) {
                Change c = ch.pollFirst();
                c.apply(array);
            }
            lastStep = curr.day;

            boolean ok = false;
            for (int i = curr.left; i < curr.right; i++) {
                int j = i + SHIFT;
                if (array[j] < curr.strength) {
                    ok = true;
                }
            }

            if (ok) {
                ch.add(new Change(curr.left, curr.right, curr.strength));
                result++;
            }

            curr.count--;
            curr.left += curr.d_left;
            curr.right += curr.d_left;
            curr.strength += curr.d_strength;
            curr.day += curr.d_day;

            if (curr.count > 0) {
                q.add(curr);
            }
        }

        out.printf("Case #%d: %d\n", testCount++, result);
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

}
