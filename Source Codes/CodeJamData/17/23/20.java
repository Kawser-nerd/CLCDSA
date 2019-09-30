import java.io.*;
import java.text.Format;
import java.util.Formatter;
import java.util.StringTokenizer;

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    FastReader() {
        try {
            br = new BufferedReader(new InputStreamReader(new FileInputStream("C:\\programs\\contests\\170422gcj\\b\\src\\input.txt")));
        } catch (Exception e) {
            e.printStackTrace();
        }
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

};

public class Main {
    static FastReader reader;
    static BufferedWriter out;
    final static long INF = 1000l * 1000l * 1000l * 1000l * 1000l;
    static void Solve(int index) {
        Formatter frm = new Formatter(out);
        int n = reader.nextInt(), q = reader.nextInt();
        int[] dst = new int[n + 1];
        int[] spd = new int[n + 1];
        long[][] e = new long[n + 1][n + 1];
        double[][] f = new double[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            dst[i] = reader.nextInt();
            spd[i] = reader.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = reader.nextInt();
                if (x != -1) e[i][j] = (long)x;
                else e[i][j] = INF;
            }
            e[i][i] = 0;
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    e[i][j] = Long.min(e[i][j], e[i][k] + e[k][j]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (dst[i] >= e[i][j]) {
                    f[i][j] = (double) e[i][j] / (double) spd[i];
                } else {
                    f[i][j] = (double)INF;
                }
            }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[i][j] = Double.min(f[i][j], f[i][k] + f[k][j]);

        frm.format("Case #%d:", index).flush();
        for (int i = 0; i < q; i++) {
            int u = reader.nextInt(), v = reader.nextInt();
            frm.format(" %.9f", f[u][v]).flush();
        }
        frm.format("\n").flush();
    }

    public static void main(String[] args) {
        reader = new FastReader();
        try {
            out = new BufferedWriter(new FileWriter("output.txt"));
        } catch (Exception e) {
        }
        int n = reader.nextInt();
        for (int i = 0; i < n; i++) {
            Solve(i + 1);
        }
    }
}
