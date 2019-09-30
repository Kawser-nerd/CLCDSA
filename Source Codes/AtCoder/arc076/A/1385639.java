import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        
        long[] f = new long[111111];
        static final long MOD = (long) (1e9+7);
        private void preprocess()
        {
            f[0] = f[1] = 1;
            for(int i=2;i<f.length;i++)
                f[i] = (f[i-1] * i) % MOD;
        }
        
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            preprocess();
            int a = in.nextInt();
            int b = in.nextInt();
            if(Math.abs(a-b)>1)
            {
                out.print(0);
            }else
            {
                if(Math.abs(a-b)==1)
                {
                    out.print((f[a] * f[b]) % MOD);
                }
                else
                {
                    out.print(((long) 2 * f[a] * f[b]) % MOD);
                }
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}