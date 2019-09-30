import java.util.*;
import java.io.*;

public class Main{


    static int gcd(int x, int y){return y==0?x:gcd(y, x%y);}
    public static void main(String[] args) {
        FastReader in = new FastReader();
        int a=0, n = in.nextInt();
        for (int l = 0; l < n; ++l){
            a=gcd(a, in.nextInt());
        }
        System.out.println(a);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}