import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

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

    void go() throws IOException {

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
    double eps = 0.00000001;

    int n;
    int m;

    //ArrayList<Pair>[] g = new ArrayList[2000000];

    void solve() throws IOException {

        String s1 = in.next();
        String s2 = in.next();

        if (!s1.equals(s2) && s2.indexOf('1') < 0) {

            System.out.println(-1);
            return;
        }

        if (s1.equals(s2)) {
            System.out.println(0);
            return;
        }

        int n = s1.length();

        int[] a = new int[n];
        int[] b = new int[n];
        int[] ra = new int[n];
        int[] rb = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = s1.charAt(i) - '0';
            b[i] = s2.charAt(i) - '0';
        }

        for (int i = 0; i < n; i++) {
            ra[i] = s1.charAt(n-i-1) - '0';
            rb[i] = s2.charAt(n-i-1) - '0';
        }

        out.println(Math.min(f(a, b), f(ra, rb)));
    }

    long f(int[] a, int[] b) {

        int n = a.length;
        int[] c = new int[n];
        int fp = 0;
        long ans = Long.MAX_VALUE;
        int[] r = new int[n];

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (a[j] != b[(j+i)%n])
                    sum++;
            r[i] = sum;
        }

        while (b[fp] != 1)
            fp++;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++)
                if (b[j] == 1)
                    c[j] = -1;

            int last = -1;
            long sum;
            int maxmove = 0;
            for (int j = n-1; j >= 0; j--) {

                if (b[j] == 1) {
                    last = j;
                }

                if (c[j] != -1 && a[j] == 1 && b[j] == 0) {
                    if (last == -1) {
                        maxmove = Math.max(maxmove, fp + n-j);
                    }
                    else {
                        maxmove = Math.max(maxmove, last - j);
                    }
                }
            }

            for (int k = 0; k < n; k++) {

                if (k >= maxmove) {
                    sum = r[((k-i)%n+n)%n];
                }
                else {
                    sum = r[((k-i)%n+n)%n] + (maxmove - k)*2;
                }


                ans = Math.min(ans, k+sum+i);
            }

            //System.err.println(i+" "+maxmove+" "+ans);

            int first = a[0];
            int first2 = c[0];
            for (int j = 0; j < n-1; j++) {
                a[j] = a[j+1];
                c[j] = c[j+1];
            }
            a[n-1] = first;
            c[n-1] = first2;
        }

        return ans;
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