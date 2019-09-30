import java.util.*;
import java.io.*;

public class Main{



    public static void main(String[] args) {
        FastReader in = new FastReader();
        TreeSet<Long> shrines = new TreeSet<Long>(), temples = new TreeSet<Long>();
        int a = in.nextInt(), b = in.nextInt(), q = in.nextInt();
        for (int l = 0; l < a; ++l){
            shrines.add(in.nextLong());
        }
        for (int l = 0; l < b; ++l){
            temples.add(in.nextLong());
        }
        for (int l = 0; l < q; ++ l){
            long x = in.nextLong();
            Long lshrine = shrines.floor(x);
            lshrine = (lshrine == null?(1L<<60):x - lshrine);
            Long rshrine = shrines.ceiling(x);
            rshrine = (rshrine == null?(1L<<60):rshrine - x);
            Long ltemple = temples.floor(x);
            ltemple = (ltemple == null?(1L<<60):x - ltemple);
            Long rtemple = temples.ceiling(x);
            rtemple = (rtemple == null?(1L<<60):rtemple - x);
            //System.out.println(lshrine + " " + rshrine + " " + ltemple + " " + rtemple);
            System.out.println(Math.min(Math.min(Math.max(lshrine, ltemple), Math.max(rshrine, rtemple)),
                               Math.min(Math.min(lshrine*2+rtemple, ltemple*2+rshrine),
                               Math.min(lshrine+2*rtemple, ltemple+2*rshrine))));
        }

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