import java.io.BufferedReader;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream in = System.in;
        OutputStream out = System.out;
        FastScanner fs = new FastScanner(in);
        PrintWriter pw = new PrintWriter(out);
        String S = fs.next();
        String[] tmp = S.split("/", 0);
        Integer[] array = new Integer[3];
        for(int i = 0; i < 3; i++) {
            array[i] = Integer.parseInt(tmp[i]);
        }
        boolean flag = false;
        if(array[0] < 2019) {
            flag = true;
        } else if(array[0] == 2019) {
            if(array[1] <= 4) {
                flag = true;
            }
        }
        if(flag) System.out.println("Heisei");
        else System.out.println("TBD");
        pw.close();
    }
}

class FastScanner {

    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;
 
    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }
 
    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                    throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken("\n");
    }
 
    public long nextLong() {
        return Long.parseLong(next());
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
 
    public double nextDouble() {
        return Double.parseDouble(next());
    }
 
    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }
 
    public long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nextLong();
        return a;
    }
 
}