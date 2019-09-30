import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            solve(in);
        }
    }

    @SuppressWarnings("unchecked")
    private static void solve(Scanner in) {
        int N = in.nextInt(), M = in.nextInt();
        int[] l = new int[N + 1], r = new int[N + 1];
        List<Integer>[] nByLen = new List[M + 1];

        for (int n = 1; n < N + 1; n++) {
            l[n] = in.nextInt();// 1 <= l <= r <= M
            r[n] = in.nextInt();
            int len = r[n] - l[n] + 1;
            if (nByLen[len] == null) {
                nByLen[len] = new ArrayList<>();
            }
            nByLen[len].add(n);
        }

        int accum = N;
        Fenwick F = new Fenwick(M);

        StringBuilder ans = new StringBuilder();
        for (int d = 1; d < M + 1; d++) {
            int sum = accum;
            for (int e = d; e < M + 1; e += d) {
                sum += F.accum(e);
            }
            if (nByLen[d] != null) {
                accum -= nByLen[d].size();
                for (int n : nByLen[d]) {
                    F.add(l[n], 1);
                    F.add(r[n] + 1, -1);
                }
            }
            ans.append(sum).append('\n');
        }
        System.out.println(ans);
    }
}

class Fenwick {
    private final int[] fenwick;

    public Fenwick(int n) {
        fenwick = new int[n + 1];
    }

    public int accum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += fenwick[i];
        }
        return sum;
    }

    public int sum(int begin, int end) {
        return accum(end) - accum(begin - 1);
    }

    public void add(int i, int a) {
        for (; i < fenwick.length; i += i & -i) {
            fenwick[i] += a;
        }
    }
}