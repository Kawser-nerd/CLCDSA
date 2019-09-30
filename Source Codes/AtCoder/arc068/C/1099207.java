import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // test
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        @SuppressWarnings("unchecked")
        List<LR> list[] = new List[m + 1];
        for (int i = 1; i <= m; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 1; i < n + 1; i++) {
            st = new StringTokenizer(in.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            list[end - start + 1].add(new LR(start, end));
        }
        int[] fen = new int[m + 1];
        int accum = n;
        for (int i = 1; i < m + 1; i++) {
            int ans = 0;
            for (int j = i; j < m + 1; j += i) {
                ans += accum(fen, j);
            }
            for (LR temp : list[i]) {
                add(temp.l, 1, fen);
                add(temp.r + 1, -1, fen);
            }
            System.out.println(ans + accum);
            accum -= list[i].size();
        }
    }

    static class LR {
        final int l, r;

        LR(int start, int end) {
            this.l = start;
            this.r = end;
        }
    }

    static int accum(int[] fen, int i) {
        int ans = 0;
        while (i > 0) {
            ans += fen[i];
            i -= (i & -i);
        }
        return ans;
    }

    static void add(int i, int a, int[] fen) {
        while (i < fen.length) {
            fen[i] += a;
            i += (i & -i);
        }
    }
}