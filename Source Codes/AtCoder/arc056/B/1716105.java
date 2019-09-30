import java.util.*;

/**
 * ???????????Union find?S?????????
 */
public class Main {
    public static void main(String[] args) {
        new Solver().solve(new Scanner(System.in));
//        new Solver().solve(new Scanner(ex));
    }

//    private static final String ex = "3 3 2\n" +
//            "1 2\n" +
//            "2 3\n" +
//            "1 3";
    private static final String ex = "5 6 5\n" +
        "1 5\n" +
        "3 5\n" +
        "3 2\n" +
        "4 1\n" +
        "1 2\n" +
        "4 3";
//    private static final String ex = "5 5 5\n" +
//        "1 4\n" +
//        "4 3\n" +
//        "3 2\n" +
//        "2 5\n" +
//        "5 1";
}

class Solver {
    Solver() {}

    void solve(Scanner scanner) {
        int[] split = splitInt(scanner.nextLine());

        int N = split[0];
        int M = split[1];
        int S = split[2];

        List<Integer>[] neighbors = new List[N + 1];
        for (int i = 0; i < N + 1; i ++) {
            neighbors[i] = new LinkedList<>();
        }

        for (int i = 0; i < M; i ++) {
            split = splitInt(scanner.nextLine());
            int u = split[0];
            int v = split[1];
            neighbors[Math.min(u, v)].add(Math.max(u, v));
        }

        List<Integer> result = new LinkedList<>();
        UnionFind uf = new UnionFind(N + 1);
        for (int i = N; i >= 0; i --) {
            for (Integer u: neighbors[i]) {
                uf.union(u, i);
            }

            if (uf.find(i, S)) result.add(i);
        }

        Collections.sort(result);

        for (Integer i: result) {
            System.out.println(i);
        }
    }

    private int[] splitInt(String s) {
        String[] split = s.split(" ");
        int[] splitInt = new int[split.length];
        for (int i = 0; i < split.length; i ++) {
            splitInt[i] = Integer.parseInt(split[i]);
        }
        return splitInt;
    }

    private long[] splitLong(String s) {
        String[] split = s.split(" ");
        long[] splitLong = new long[split.length];
        for (int i = 0; i < split.length; i ++) {
            splitLong[i] = Long.parseLong(split[i]);
        }
        return splitLong;
    }

}

class UnionFind {
    int[] nums;

    UnionFind(int n) {
        nums = new int[n];
        for (int i = 0; i < n; i ++) {
            nums[i] = i;
        }
    }

    int root(int a) {
        if (nums[a] == a) return a;

        int root = root(nums[a]);
        nums[a] = root;

        return root;
    }

    void union(int a, int b) {
        if (!find(a, b)) {
            int rootA = root(a);
            int rootB = root(b);
            nums[rootA] = rootB;
        }
    }

    boolean find(int a, int b) {
        int distA = root(a);
        int distB = root(b);

        return distA == distB;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.