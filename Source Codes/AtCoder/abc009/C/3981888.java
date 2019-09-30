import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Main {
    static final int ALP = 26;

    static int[] before;
    static int[] after;

    static int f() {
        int ret = 0;
        for (int i = 0; i < ALP; i++) ret += Math.min(before[i], after[i]);
        return ret;
    }

    public static void main(String[] args) throws IOException {
        final String NK;
        final String S;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            NK = reader.readLine();
            S = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = NK.split(" ");
        final int N = Integer.parseInt(sl[0]);
        final int K = Integer.parseInt(sl[1]);

        before = new int[ALP];
        after = new int[ALP];

        Arrays.fill(before, 0);

        for (int i = 0; i < N; i++) before[S.charAt(i) - 'a']++;

        System.arraycopy(before, 0, after, 0, before.length);

        StringBuilder sb = new StringBuilder();

        int len = S.length();
        int dif = 0;
        int curlen = len;
        
        int i = 0;

        while (i < len) {
            for (int j = 0; j < after.length; j++) {
                char chr = (char)('a' + j);

                if (after[j] < 1) continue;

                char chrs = S.charAt(i);
                int idxs = chrs - 'a';

                before[idxs]--;
                after[j]--;
                curlen--;

                boolean flg = false;
                if (j != idxs) {
                    dif++;
                    flg = true;
                }

                int rem = curlen - f();

                if (dif + rem <= K) {
                    sb.append(chr);
                    i++;
                    break;
                } else {
                    before[idxs]++;
                    after[j]++;
                    curlen++;
                    if (flg) dif--;
                }
            }
        }

        out.println(sb);

        out.flush();
    }
}