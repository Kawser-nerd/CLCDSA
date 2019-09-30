import com.sun.rowset.internal.InsertRow;
import com.sun.xml.internal.ws.api.message.Attachment;
import sun.nio.ch.ThreadPool;

import javax.swing.event.InternalFrameAdapter;
import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    class Tribe {
        int first;
        int times;
        int west;
        int east;
        int strength;
        int period;
        int change;
        int drift;

        int getStrength(int time) {
            return strength + change * time;
        }

        int getWest(int time) {
            return west + drift * time;
        }

        int getEast(int time) {
            return east + drift * time;
        }

        int getDay(int time) {
            return first + time * period;
        }
    }

    class Attack implements Comparable<Attack> {
        Tribe tribe;
        int time;

        Attack(Tribe tribe, int time) {
            this.tribe = tribe;
            this.time = time;
        }

        int getDay() {
            return tribe.getDay(time);
        }

        int getWest() {
            return tribe.getWest(time);
        }

        int getEast() {
            return tribe.getEast(time);
        }

        int getStrength() {
            return tribe.getStrength(time);
        }

        public int compareTo(Attack o) {
            return getDay() - o.getDay();
        }
    }

    class SegmentTree {
        TreeMap<Integer, Integer> indexer;
        int[] t;
        int size;

        SegmentTree(TreeMap<Integer, Integer> indexer) {
            this.indexer = indexer;

            int n = 1;
            while (4 * indexer.size() > n) {
                n *= 2;
            }

            size = n;
            t = new int[2 * n];
        }

        int index(int x) {
            return 2 * indexer.get(x);
        }

        boolean successful(Attack attack) {
            int from = index(attack.getWest());
            int to = index(attack.getEast());
            return min(1, 0, size - 1, from, to) < attack.getStrength();
        }

        void applyFix(Attack attack) {
            int from = index(attack.getWest());
            int to = index(attack.getEast());
            apply(1, 0, size - 1, from, to, attack.getStrength());
        }


        private int min(int node, int left, int right, int from, int to) {
            int queryLeft = Math.max(from, left);
            int queryRight = Math.min(to, right);

            if (queryLeft > queryRight) {
                return Integer.MAX_VALUE;
            }

            if (queryLeft == left && queryRight == right) {
                return t[node];
            }

            int mid = getMid(left, right);
            int leftSon = leftSon(node);
            int rightSon = rightSon(node);

            t[leftSon] = Math.max(t[leftSon], t[node]);
            t[rightSon] = Math.max(t[rightSon], t[node]);
            return Math.min(min(leftSon, left, mid, from, to), min(rightSon, mid + 1, right, from, to));
        }

        private void apply(int node, int left, int right, int from, int to, int value) {
            int queryLeft = Math.max(from, left);
            int queryRight = Math.min(to, right);

            if (queryLeft > queryRight) {
                return;
            }

            if (queryLeft == left && queryRight == right) {
                t[node] = Math.max(t[node], value);
                return;
            }

            int mid = getMid(left, right);
            int leftSon = leftSon(node);
            int rightSon = rightSon(node);

            t[leftSon] = Math.max(t[leftSon], t[node]);
            t[rightSon] = Math.max(t[rightSon], t[node]);
            apply(leftSon, left, mid, from, to, value);
            apply(rightSon, mid + 1, right, from, to, value);
            t[node] = Math.min(t[leftSon], t[rightSon]);
        }

        private int getMid(int left, int right) {
            return (left + right) / 2;
        }

        private int rightSon(int node) {
            return 2 * node + 1;
        }

        private int leftSon(int node) {
            return 2 * node;
        }
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int testcase = 1; testcase <= tests; testcase++) {

            List<Tribe> tribes = new ArrayList<Tribe>();
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                Tribe tribe = new Tribe();
                tribe.first = in.nextInt();
                tribe.times = in.nextInt();
                tribe.west = in.nextInt();
                tribe.east = in.nextInt();
                tribe.strength = in.nextInt();
                tribe.period = in.nextInt();
                tribe.drift = in.nextInt();
                tribe.change = in.nextInt();

                tribes.add(tribe);
            }

            TreeMap<Integer, Integer> indexer = new TreeMap<Integer, Integer>();
            for (Tribe tribe : tribes) {
                for (int time = 0; time <= tribe.times; time++) {
                    indexer.put(tribe.getEast(time), 0);
                    indexer.put(tribe.getWest(time), 0);
                }
            }

            int at = 0;
            for (Map.Entry<Integer, Integer> entry : indexer.entrySet()) {
                entry.setValue(at++);
            }

            List<Attack> attacks = new ArrayList<Attack>();
            for (Tribe tribe : tribes) {
                for (int time = 0; time < tribe.times; time++) {
                    attacks.add(new Attack(tribe, time));
                }
            }
            Collections.sort(attacks);

            SegmentTree tree = new SegmentTree(indexer);
            int answer = 0;
            List<Attack> buffer = new ArrayList<Attack>();
            for (Attack attack : attacks) {
                if (!buffer.isEmpty() && attack.getDay() != buffer.get(0).getDay()) {
                    for (Attack toApply : buffer) {
                        tree.applyFix(toApply);
                    }
                    buffer.clear();
                }
                if (tree.successful(attack)) {
                    answer++;
                }
                buffer.add(attack);
            }

            out.println("Case #" + testcase + ": " + answer);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }
}