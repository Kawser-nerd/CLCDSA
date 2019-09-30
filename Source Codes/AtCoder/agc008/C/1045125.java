import java.io.*;
import java.util.StringTokenizer;
 
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int i = in.nextInt();
            int o = in.nextInt();
            int t = in.nextInt();
            int j = in.nextInt();
            int l = in.nextInt();
            int s = in.nextInt();
            int z = in.nextInt();
            long res = o;
            int modCnt = i%2 + j%2 + l%2;
            if (modCnt > 1 && i > 0 && j > 0 && l > 0) {
                i--; j--; l--; res+=3;
            }
            res += (i / 2) * 2;res += (j / 2) * 2;res += (l / 2) * 2;
            out.println(res);
 
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