import java.io.*;
import java.util.*;
import java.util.function.IntPredicate;

class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    public static int upperBound(int lb, int ub, IntPredicate pred) {
        if (! pred.test(lb)) return lb;
        assert !pred.test(ub);
        while (lb + 1 < ub) {
            int mid = (ub - lb) / 2 + lb;
            if (pred.test(mid)) lb = mid;
            else ub = mid;
        }
        return ub;
    }

    final int INF = Integer.MAX_VALUE / 4;
    final int Z = 26;

    void solve() {
        String s = "";
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try { s = reader.readLine(); } catch (IOException e) {}
        final int N = s.length();
        final boolean[] used = new boolean[Z]; Arrays.fill(used, false);
        final int[] len = new int[N + 1]; len[N] = 1;
        int count = Z;
        int length = 0;
        final ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>(Z);
        for (int i = 0; i < Z; i++) a.add(new ArrayList<Integer>());
        for (int i = N - 1; i >= 0; i--) {
            char c = s.charAt(i);
            int c_index = (int)(c - 'a');
            a.get(c_index).add(i);
            len[i] = len[i + 1];
            if (used[c_index]) continue;
            used[c_index] = true;
            count--;
            if (count == 0) {
                Arrays.fill(used, false);
                count = Z;
                length++;
                len[i]++;
            }
        }
        for (ArrayList<Integer> xs : a) Collections.reverse(xs);
        StringBuilder builder = new StringBuilder();
        int cur = -1;
        for (int i = length; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                ArrayList<Integer> xs = a.get(j);
                final int _cur = cur;
                int next = upperBound(0, xs.size(), (IntPredicate)(int k) -> { 
                    return k >= xs.size() ? false : xs.get(k) <= _cur; 
                });
                int k = next >= xs.size() ? N : xs.get(next);
                if (k == N) {
                    builder.append((char)(j + 'a'));
                    break;
                } else if (len[k + 1] == i) {
                    cur = k;
                    builder.append((char)(j + 'a'));
                    break;
                }
            }
        }
        System.out.println(builder.toString());
    }
}