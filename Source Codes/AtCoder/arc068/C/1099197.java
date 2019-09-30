import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        solve(new BufferedReader(new InputStreamReader(System.in)));
    }

    private static void solve(BufferedReader in) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

        @SuppressWarnings("unchecked")
        List<LR>[] nByLen = new List[M + 1];

        for (int n = 1; n < N + 1; n++) {
            st = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(st.nextToken());// 1 <= l <= r <= M
            int r = Integer.parseInt(st.nextToken());
            LR lr = new LR(l, r);
            if (nByLen[lr.len] == null) {
                nByLen[lr.len] = new ArrayList<>();
            }
            nByLen[lr.len].add(lr);
        }

        int accum = N;

        fenwick = new int[M + 1];
        for (int d = 1; d < M + 1; d++) {
            int sum = accum;
            for (int e = d; e < M + 1; e += d) {
                sum += faccum(e);
            }
            System.out.println(sum);
            if (nByLen[d] != null) {
                accum -= nByLen[d].size();
                for (LR lr : nByLen[d]) {
                    fadd(lr.l, 1);
                    fadd(lr.r + 1, -1);
                }
            }
        }
    }

    private static class LR {
        final int l, r, len;

        LR(int l, int r) {
            this.l = l;
            this.r = r;
            this.len = r - l + 1;
        }
    }

    private static int[] fenwick;

    private static int faccum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += fenwick[i];
        }
        return sum;
    }

    private static void fadd(int i, int a) {
        for (; i < fenwick.length; i += i & -i) {
            fenwick[i] += a;
        }
    }
}