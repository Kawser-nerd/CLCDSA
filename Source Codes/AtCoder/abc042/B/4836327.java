import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Twinkle Twinkle Little Star
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BIrohaLovesStringsABCEdition solver = new BIrohaLovesStringsABCEdition();
        solver.solve(1, in, out);
        out.close();
    }

    static class BIrohaLovesStringsABCEdition {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int row = in.nextInt();
            int col = in.nextInt();
            String array[] = new String[row];
            for (int i = 0; i < row; i++) {
                array[i] = in.next();
            }
            Arrays.sort(array);
            String temp = "";
            for (int i = 0; i < row; i++) {
                temp += array[i];
            }
            out.print(temp);
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