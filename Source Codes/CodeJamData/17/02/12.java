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
            in = new Reader("B-large (1).in");
            out = new PrintWriter( new BufferedWriter(new FileWriter("output.txt")) );
        }
        catch (Exception e) {

            //br = new BufferedReader( new InputStreamReader( System.in ) );
            in = new Reader();
            out = new PrintWriter( new BufferedWriter(new OutputStreamWriter(System.out)) );
        }
    }

    int inf = 2000000000;
    int mod = 1000000007;
    double eps = 0.00000001;

    int n;
    int m;

    //ArrayList<Pair>[] g = new ArrayList[2000000];

    int z = 400010;


    void solve() throws IOException {

        int cnt = 0;
        long n = in.nextLong();
        boolean cary = false;
        long prev = 10;
        int[] ans = new int[20];
        int p = 0;
        while (n > 0) {

            long x = n%10;
            n /= 10;
            if (cary) {
                x--;
                cary = false;
            }

            if (x > prev) {
                x--;
                cnt = p;
            }

            if (x < 0) {
                if (n > 0)
                    x = 9;
                else
                    x = 0;
                cary = true;
            }

            ans[p++] = (int)x;
            prev = x;
        }

        for (int i = 0; i < cnt; i++)
            ans[i] = 9;

        while (ans[p-1] == 0 && p > 1)
            p--;

        for (int i = p-1; i >= 0; i--) {
            out.print(ans[i]);
        }
    }

    void go() throws IOException {

        int t = in.nextInt();
        int cs = 1;

        while (t > 0) {
            out.print("Case #"+cs+": ");
            solve();
            out.println();
            cs++;
            t--;
        }

        out.flush();
        out.close();
    }

    class Pair implements Comparable<Pair>{

        int a;
        int b;

        Pair(int a, int b) {

            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair p) {

            if (b > p.b) return 1;
            if (b < p.b) return -1;
            if (a > p.a) return 1;
            if (a < p.a) return -1;
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