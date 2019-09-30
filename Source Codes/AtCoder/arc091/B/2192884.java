import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) throws Exception {

        new Main().go();
    }

    PrintWriter out;
    Parser in;
    BufferedReader br;

    Main() throws IOException {

        try {

            //br = new BufferedReader( new FileReader("input.txt") );
            //in = new Reader("input.txt");
            in = new Parser(new FileInputStream("input.txt"));
            out = new PrintWriter( new BufferedWriter(new FileWriter("output.txt")) );
        }
        catch (Exception e) {

            //br = new BufferedReader( new InputStreamReader( System.in ) );
            in = new Parser(System.in);
            out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );
        }
    }

    void go() throws Exception {

        long time = System.currentTimeMillis();

        int t = 1;
        while (t > 0) {
            solve();
            //out.println();
            t--;
        }

        //System.err.println(System.currentTimeMillis() - time);

        out.flush();
        out.close();
    }


    int inf = 2000000000;
    int mod = 1000000007;
    double eps = 0.000000001;

    int n;
    int m;

    void solve() throws IOException {

        int n = in.nextInt();
        int k = in.nextInt();

        long res = 1l*n*n;

        for (int i = 1; i <= n; i++) {

            int r = Math.min(i-1, k-1);

            if (r < 0)
                continue;

            int d1 = n%i+1;

            long sum = 1l * n/i * Math.min(d1, r+1);
            if (d1 < r + 1)
                sum += 1l * (n/i-1) * (r+1-d1);

            sum += r;
            res -= sum;
        }

        out.println(res);
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

    class Parser {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Parser(InputStream in) {
            din = new DataInputStream(in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead =  0;
        }
        public String nextString(int maxSize) {
            byte[] ch = new byte[maxSize];
            int point =  0;
            try {
                byte c = read();
                while (c == ' ' || c == '\n' || c=='\r')
                    c = read();
                while (c != ' ' && c != '\n' && c!='\r') {
                    ch[point++] = c;
                    c = read();
                }
            } catch (Exception e) {}
            return new String(ch, 0,point);
        }
        public int nextInt() {
            int ret =  0;
            boolean neg;
            try {
                byte c = read();
                while (c <= ' ')
                    c = read();
                neg = c == '-';
                if (neg)
                    c = read();
                do {
                    ret = ret * 10 + c - '0';
                    c = read();
                } while (c > ' ');

                if (neg) return -ret;
            } catch (Exception e) {}
            return ret;
        }
        public long nextLong() {
            long ret =  0;
            boolean neg;
            try {
                byte c = read();
                while (c <= ' ')
                    c = read();
                neg = c == '-';
                if (neg)
                    c = read();
                do {
                    ret = ret * 10 + c - '0';
                    c = read();
                } while (c > ' ');

                if (neg) return -ret;
            } catch (Exception e) {}
            return ret;
        }
        private void fillBuffer() {
            try {
                bytesRead = din.read(buffer, bufferPointer =  0, BUFFER_SIZE);
            } catch (Exception e) {}
            if (bytesRead == -1) buffer[ 0] = -1;
        }

        private byte read() {
            if (bufferPointer == bytesRead) fillBuffer();
            return buffer[bufferPointer++];
        }
    }

}