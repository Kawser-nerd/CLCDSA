import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            solve(in);
        }
    }

    private static void solve(BufferedReader in) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

        int[] l = new int[N + 1], r = new int[N + 1];
        @SuppressWarnings("unchecked")
        List<Integer>[] nByLen = new List[M + 1];

        for (int n = 1; n < N + 1; n++) {
            st = new StringTokenizer(in.readLine());
            l[n] = Integer.parseInt(st.nextToken());// 1 <= l <= r <= M
            r[n] = Integer.parseInt(st.nextToken());
            int len = r[n] - l[n] + 1;
            if (nByLen[len] == null) {
                nByLen[len] = new ArrayList<>();
            }
            nByLen[len].add(n);
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
                for (int i : nByLen[d]) {
                    fadd(l[i], 1);
                    fadd(r[i] + 1, -1);
                }
            }
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