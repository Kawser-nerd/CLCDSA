import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    char[] a, b;
    int[] as, bs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        long tempA = sc.nextLong() - 1;
        a = String.valueOf(tempA).toCharArray();
        b = sc.next().toCharArray();
        as = new int[a.length];
        bs = new int[b.length];
        for (int i = 0; i < a.length; i++) {
            as[i] = Character.getNumericValue(a[i]);
        }
        for (int i = 0; i < b.length; i++) {
            bs[i] = Character.getNumericValue(b[i]);
        }
        solve();
    }

    void solve() {
        long[][][] dp1 = new long[20][2][2];
        dp1[0][0][0] = 1;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int limit = j > 0 ? 9 : as[i];
                    for (int l = 0; l <= limit; l++) {
                        int jNum = j;
                        if (l < limit) {
                            jNum = 1;
                        }
                        int kNum = k;
                        if (l == 4 || l == 9) {
                            kNum = 1;
                        }
                        dp1[i + 1][jNum][kNum] += dp1[i][j][k];
                    }
                }
            }
        }
        long aNum = 0;
        for (int j = 0; j < 2; j++) {
            aNum += dp1[a.length][j][1];
        }
        long[][][] dp2 = new long[20][2][2];
        dp2[0][0][0] = 1;
        for (int i = 0; i < b.length; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int limit = j > 0 ? 9 : bs[i];
                    for (int l = 0; l <= limit; l++) {
                        int jNum = j;
                        if (l < limit) {
                            jNum = 1;
                        }
                        int kNum = k;
                        if (l == 4 || l == 9) {
                            kNum = 1;
                        }
                        dp2[i + 1][jNum][kNum] += dp2[i][j][k];
                    }
                }
            }
        }
        long bNum = 0;
        for (int j = 0; j < 2; j++) {
            bNum += dp2[b.length][j][1];
        }

        System.out.println(bNum - aNum);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}