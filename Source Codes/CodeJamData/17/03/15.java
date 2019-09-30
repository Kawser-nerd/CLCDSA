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
            in = new Reader("C-large.in");
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

        long n = in.nextLong();
        long k = in.nextLong();

        long x1 = n-1;
        long x2 = n;

        long cnt1 = 0;
        long cnt2 = 1;

        long min = 0;
        long max = 0;

        while (k > 0) {

            long nx1 = 0;
            long ncnt1 = 0;

            if (cnt2 >= k) {

                min = (x2-1)/2;
                max = x2 / 2;
                break;
            }

            k -= cnt2;

            if (x2%2 == 1)
                cnt2 *= 2;
            else
                ncnt1 = cnt2;

            x2 = x2/2;
            nx1 = x2-1;

            if (cnt1 >= k) {

                min = (x1-1)/2;
                max = x1 / 2;
                break;
            }

            k -= cnt1;
            if (x1%2 == 1)
                ncnt1 += cnt1*2;
            else {
                ncnt1 += cnt1;
                cnt2 += cnt1;
            }

            x1 = nx1;
            cnt1 = ncnt1;
        }

        out.print(max+" "+min);
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