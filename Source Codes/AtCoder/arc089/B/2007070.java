import javax.xml.bind.DatatypeConverter;
import java.io.*;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {

        new Main().go();
    }

    PrintWriter out;
    Reader in;
    BufferedReader br;

    Main() throws IOException {

        try {

            //br = new BufferedReader( new FileReader("input.txt") );
            in = new Reader("input.txt");
            out = new PrintWriter( new BufferedWriter(new FileWriter("output.txt")) );
        }
        catch (Exception e) {

            //br = new BufferedReader( new InputStreamReader( System.in ) );
            in = new Reader();
            out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );
        }
    }

    void go() throws Exception {

        int t = 1;
        while (t > 0) {
            solve();
            //out.println();
            t--;
        }

        out.flush();
        out.close();
    }


    int inf = 2000000000;
    int mod = 1000000007;
    double eps = 0.000000001;

    int n;
    int m;

    //ArrayList<Integer>[] g = new ArrayList[1000];

    int mx = 1000;

    void solve() throws IOException, NoSuchAlgorithmException {

        int n = in.nextInt();
        k = in.nextInt();

        int[][] w = new int[k*2][k*2];
        int[][] b = new int[k*2][k*2];

        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            String c = in.next();
            if (c.equals("W"))
                w[x%(k*2)][y%(k*2)]++;
            else
                b[x%(k*2)][y%(k*2)]++;
        }

        for (int i = 0; i < k*2 ; i++)
            for (int j = 0; j < k*2; j++) {

                int s1 = 0;
                int s2 = 0;
                int s3 = 0;

                if (i > 0)
                    s1 = w[i-1][j];
                if (j > 0)
                    s2 = w[i][j-1];

                if (i > 0 && j > 0)
                    s3 = w[i-1][j-1];

                w[i][j] += s1 + s2 - s3;
            }

        for (int i = 0; i < 2*k ; i++)
            for (int j = 0; j < 2*k; j++) {

                int s1 = 0;
                int s2 = 0;
                int s3 = 0;

                if (i > 0)
                    s1 = b[i-1][j];
                if (j > 0)
                    s2 = b[i][j-1];

                if (i > 0 && j > 0)
                    s3 = b[i-1][j-1];

                b[i][j] += s1 + s2 - s3;
            }

        int ans = 0;

        int sw;
        int sb;
        int allw = w[2*k-1][2*k-1];
        int allb = b[2*k-1][2*k-1];

        //System.err.println(sum(1, 0, 2, 0, b));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                sw = sum(i, j, w, k);
                sb = sum(i, j+k, b, k);
                sw += sum(i+k, j+k, w, k);
                sb += sum(i+k, j, b, k);
                ans = Math.max(ans, sb+sw);

                sb = sum(i, j, b, k);
                sw = sum(i, j+k, w, k);
                sb += sum(i+k, j+k, b, k);
                sw += sum(i+k, j, w, k);
                ans = Math.max(ans, sb+sw);
            }
        }

        out.println(ans);
    }

    int k;

    int sum(int i, int j, int[][] s, int k) {
        int y = Math.min(2 * k - 1, j + k - 1);
        int x = Math.min(2 * k - 1, i + k - 1);
        int sw = sum(i, j, x, y, s);
        sw += sum(i, y+1, x, j+k-1, s);
        sw += sum(x+1, y+1, i+k-1, j+k-1, s);
        sw += sum(x+1, j, i+k-1, y, s);
        return sw;
    }

    int sum(int x1, int y1, int x2, int y2, int[][] s) {

        if (x1 > x2 || y1 > y2)
            return 0;

        x1 %= 2*k;
        x2 %= 2*k;
        y1 %= 2*k;
        y2 %= 2*k;

        int sw = s[x2][y2];
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;

        if (x1 > 0) s1 = s[x1-1][y2];
        if (y1 > 0) s2 = s[x2][y1-1];
        if (x1 > 0 && y1 > 0) s3 = s[x1-1][y1-1];

        //System.err.println("c = "+x1+" "+y1+" "+x2+" "+y2);
        //System.err.println("s = "+sw+" "+s1+" "+s2+" "+s3);

        return sw - s1 - s2 + s3;
    }

    int gcd(int a, int b) {

        if (b == 0) return a;
        return gcd(b, a%b);
    }

    class Pair implements Comparable<Pair>{

        int a;
        int b;

        Pair(int a, int b) {

            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {

            if (a > p.a) return 1;
            if (a < p.a) return -1;
            if (b > p.b) return 1;
            if (b < p.b) return -1;
            return 0;
        }
    }

    class Item {

        int a;
        int b;
        int c;

        Item(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }

    class Reader {

        BufferedReader  br;
        StringTokenizer tok;

        Reader(String file) throws IOException {
            br = new BufferedReader( new FileReader(file) );
        }

        Reader() throws IOException {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() throws IOException {

            while (tok == null || !tok.hasMoreElements())
                tok = new StringTokenizer(br.readLine());
            return tok.nextToken();
        }

        int nextInt() throws NumberFormatException, IOException {
            return Integer.valueOf(next());
        }

        long nextLong() throws NumberFormatException, IOException {
            return Long.valueOf(next());
        }

        double nextDouble() throws NumberFormatException, IOException {
            return Double.valueOf(next());
        }


        String nextLine() throws IOException {
            return br.readLine();
        }

    }

}