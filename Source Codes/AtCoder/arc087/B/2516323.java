import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    char[] cs;
    int x, y;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        cs = sc.next().toCharArray();
        x = sc.nextInt();
        y = sc.nextInt();
        solve();
    }

    void solve() {
        boolean[][] dpX = new boolean[cs.length + 1][2 * cs.length + 1];
        boolean[][] dpY = new boolean[cs.length + 1][2 * cs.length + 1];
        dpY[0][cs.length] = true;
        int i = 0;
        int partCount = 0;
        int fCount = 0;
        while (i < cs.length) {
            if (cs[i] == 'T' || i == cs.length - 1) {
                if (i == cs.length - 1 && cs[i] == 'F') {
                    fCount++;
                }
                partCount++;
                if (partCount == 1) {
                    dpX[partCount][cs.length + fCount] = true;
                } else if (partCount % 2 != 0) {
                    for (int k = 0; k < dpX[partCount].length; k++) {
                        if (k > fCount) {
                            dpX[partCount][k] |= dpX[partCount - 2][k - fCount];
                        }
                        if (k < dpX[partCount].length - fCount) {
                            dpX[partCount][k] |= dpX[partCount - 2][k + fCount];
                        }
                    }
                } else {
                    for (int k = 0; k < dpY[partCount].length; k++) {
                        if (k > fCount) {
                            dpY[partCount][k] |= dpY[partCount - 2][k - fCount];
                        }
                        if (k < dpY[partCount].length - fCount) {
                            dpY[partCount][k] |= dpY[partCount - 2][k + fCount];
                        }
                    }
                }
                fCount = 0;
            } else if (cs[i] == 'F') {
                fCount++;
            }
            i++;
        }
        int xIndex = partCount - 1;
        int yIndex = partCount;
        if (partCount % 2 == 1) {
            xIndex = partCount;
            yIndex = partCount - 1;
        }
        if (dpX[xIndex][cs.length + x] & dpY[yIndex][cs.length + y]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
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