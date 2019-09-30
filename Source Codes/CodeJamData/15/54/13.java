import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    private static double EPS = 0.0000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(char[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + "");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static List<Integer> solve(SortedMap<Integer, Integer> nums) {
        //print(join(nums.keySet(), ", "));
        if (nums.size() == 1 && nums.get(0) == 1) return new ArrayList<Integer>();
        int max = nums.lastKey();

        outer : for (int c : nums.keySet()) {
            SortedMap<Integer, Integer> cur = new TreeMap<Integer, Integer>(nums);
            SortedMap<Integer, Integer> next = new TreeMap<Integer, Integer>();
            while (cur.size() > 0) {
                int x = (c < 0) ? cur.firstKey() : cur.lastKey(); // key containing c
                decrement(cur, x);
                if (!cur.containsKey(x - c)) continue outer;
                decrement(cur, x - c);
                increment(next, x - c);
            }
            //print("Found " + c);
            List<Integer> ans = solve(next);
            ans.add(0, c);
            return ans;
        }
        return null;
    }

    public static void decrement(SortedMap<Integer, Integer> nums, int x) {
        if (nums.get(x) == 1) nums.remove(x);
        else nums.put(x, nums.get(x) - 1);
    }
    public static void increment(SortedMap<Integer, Integer> nums, int x) {
        if (!nums.containsKey(x)) nums.put(x, 0);
        nums.put(x, nums.get(x) + 1);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            int P = nextInt();
            int[] elements = new int[P];
            int[] freq = new int[P];
            for (int i = 0; i < P; i++) elements[i] = nextInt();
            for (int i = 0; i < P; i++) freq[i] = nextInt();

            SortedMap<Integer, Integer> nums = new TreeMap<Integer, Integer>();
            for (int i = 0; i < P; i++) nums.put(elements[i], freq[i]);

            List<Integer> ans = solve(nums);
            //print(join(ans, " "));

            System.out.printf("Case #%d: %s%n", t, join(ans, " "));
        }
    }
}