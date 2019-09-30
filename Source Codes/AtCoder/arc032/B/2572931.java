import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static Scanner sc;
    private static int[][] neg8 = new int[][]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    private static int[][] neg4 = new int[][]{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    public static void main(String[] args) {
        Main instance = new Main();
        sc = instance.new Scanner();
        instance.solve();
    }

    private void solve() {
        try {
            int N = sc.nextInt();
            int M = sc.nextInt();

            UnionFind uf = new UnionFind(N);
            for (int i = 0; i < M; i++) {
                uf.unite(sc.nextInt()-1, sc.nextInt()-1);
            }

            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < N; i++) {
                set.add(uf.find(i));
            }

            System.out.println(set.size() - 1);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private class Scanner {
        String[] s;
        int i;
        BufferedReader br;
        String regex = " ";

        public Scanner() {
            s = new String[0];
            i = 0;
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        @Override
        protected void finalize() throws Throwable {
            try {
                super.finalize();
            } finally {
                destruction();
            }
        }

        private void destruction() throws IOException {
            if (br != null) br.close();
        }

        public String next() throws IOException {
            if (i < s.length) return s[i++];
            String st = br.readLine();
            while (st == "") st = br.readLine();
            s = st.split(regex, 0);
            i = 0;
            return s[i++];
        }

        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(next());
        }

        public Long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(next());
        }

        public Double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(next());
        }
    }

    private static double distance(int x1, int x2, int y1, int y2) {
        return Math.sqrt((Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2)));
    }

    private static boolean nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        boolean swap = false;
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
            swap = true;
        }
        reverse(nums, i + 1);
        return swap;
    }

    private static void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static ArrayList filledList(int n, int fill) {
        return new ArrayList<>(Collections.nCopies(n, fill));
    }

    // ?????`??`???????????????
    private static int lower_bound(List<Integer> list, int val) {
        return ~Collections.binarySearch(list, val, (x, y) -> x.compareTo(y) >= 0 ? 1 : -1);
    }

    // ?????`?????`???????????????
    private static int upper_bound(List<Integer> list, int val) {
        return ~Collections.binarySearch(list, val, (x, y) -> x.compareTo(y) > 0 ? 1 : -1);
    }

    private static class Pair<F, S> {
        F f;
        S s;

        Pair() {
        }

        Pair(F f, S s) {
            this.f = f;
            this.s = s;
        }

        Pair(Pair<F, S> p) {
            f = p.f;
            s = p.s;
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair) o;
                return f == p.f && s == p.s;
            }
            return false;
        }

        @Override
        public int hashCode() {
            return Objects.hash(f, s);
        }


        @Override
        public String toString() {
            return "{" + f.toString() + ", " + s.toString() + "}";
        }
    }

    // https://atc001.contest.atcoder.jp/tasks/unionfind_a
    private static class UnionFind {
        private int par[] = new int[100005];

        private UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        // ???????
        private int find(int x) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }

        // x?y?????????
        private void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;

            par[x] = y;
        }

        // x?y??????????
        private boolean same(int x, int y) {
            return find(x) == find(y);
        }
    }
}