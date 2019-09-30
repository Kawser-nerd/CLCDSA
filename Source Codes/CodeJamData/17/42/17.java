
import java.io.PrintStream;
import java.util.*;

public class B {

    private static final Scanner sc = new Scanner(System.in);
    private static final PrintStream out = new PrintStream(System.out);

    int N, C, M;

    static class Item implements Comparable<Item> {
        int P; // position
        int B; // customer

        public Item(int p, int b) {
            P = p;
            B = b;
        }

        @Override
        public int compareTo(Item o) {
            if (P != o.P)
                return Integer.compare(P, o.P);
            return Integer.compare(B, o.B);
        }

        @Override
        public String toString() {
            return "Item{" +
                    "P=" + P +
                    ", B=" + B +
                    '}';
        }
    }

    Item[] items;

    int can(int layers) {
        int vacant = 0, curPos = 0;
        int[] used = new int[N + 1];
        int miss = 0;
        for (Item item : items) {
            if (curPos < item.P) {
                vacant += (item.P - curPos) * layers;
                curPos = item.P;
            }
            vacant--;
            used[item.P]++;
            if (vacant < 0)
                return -1;
            if (used[item.P] > layers)
                miss++;
        }
        return miss;
    }

    private String solve() {
        N = sc.nextInt();
        C = sc.nextInt();
        M = sc.nextInt();
        items = new Item[M];
        int[] byCustomer = new int[C + 1];
        for (int i = 0; i < M; ++i) {
            items[i] = new Item(sc.nextInt(), sc.nextInt());
            byCustomer[items[i].B]++;
        }
        int rides = 0;
        for (int a : byCustomer) {
            rides = Math.max(a, rides);
        }
        Arrays.sort(items);
        while (can(rides) == -1) {
            rides++;
        }
        int miss = can(rides);
        return String.format("%d %d", rides, miss);
    }

    private void run() throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            String res = solve();
            out.printf("Case #%d: %s\n", i, res);
            System.err.println(i);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new B().run();
    }
}