import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * Created by IntelliJ IDEA.
 * User: yc14rp1
 * Date: 5/6/12
 * Time: 1:52 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test1_3 {


    private static final int LOGGING_LEVEL = 0;

    public static class Pair {
        private long n;
        private long t;

        public Pair(long n, long t) {
            this.n = n;
            this.t = t;
        }

        @Override
        public String toString() {
            return "{" +
                    "n=" + n +
                    ", t=" + t +
                    '}';
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\z3.in";
        int firstTestCase = 1;
        int lastTestCase = 10000;
        try {
            // Open the file that is the first
            // command line parameter
            FileInputStream fstream = new FileInputStream(path);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            //Read File Line By Line
            strLine = br.readLine();
            int tn = Integer.valueOf(strLine);
            for (int t = 1; t <= tn; t++) {
                strLine = br.readLine();
                String[] split = strLine.split(" ");
                int n = Integer.valueOf(split[0]);
                int m = Integer.valueOf(split[1]);
                long[] a1 = new long[n];
                long[] a2 = new long[n];
                strLine = br.readLine();
                split = strLine.split(" ");
                for (int i = 0; i < n; i++) {
                    a1[i] = Long.parseLong(split[2 * i]);
                    a2[i] = Long.parseLong(split[2 * i + 1]);
                }
                long[] b1 = new long[m];
                long[] b2 = new long[m];
                strLine = br.readLine();
                split = strLine.split(" ");
                for (int i = 0; i < m; i++) {
                    b1[i] = Long.parseLong(split[2 * i]);
                    b2[i] = Long.parseLong(split[2 * i + 1]);
                }
                if (t >= firstTestCase && t <= lastTestCase) {
                    String res = "";
                    ArrayList<Pair> la = new ArrayList<Pair>();
                    for (int i = 0; i < n; i++) {
                        la.add(new Pair(a1[i], a2[i]));
                    }
                    ArrayList<Pair> lb = new ArrayList<Pair>();
                    for (int i = 0; i < m; i++) {
                        lb.add(new Pair(b1[i], b2[i]));
                    }
                    long pairs = 0;
                    pairs += lsolve(la, lb);
                    sout("Case #" + t + ": " + Arrays.toString(a1) + Arrays.toString(a2) + Arrays.toString(b1) + Arrays.toString(b2), 1);
                    System.out.println("Case #" + t + ": " + pairs);
                }
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long lsolve(ArrayList<Pair> la, ArrayList<Pair> lb) {
        sout("solve for " + la + lb, 1);
        long solve = solve(la, lb);
        sout("solve for " + la + lb + "=" + solve, 1);
        return solve;
    }

    private static long solve(ArrayList<Pair> la, ArrayList<Pair> lb) {
        if (la.size() == 0) {
            return 0;
        }
        if (lb.size() == 0) {
            return 0;
        }
        if (la.get(0).t == lb.get(0).t) {
            long m = la.get(0).n - lb.get(0).n;
            if (m > 0) {
                ArrayList<Pair> nla = new ArrayList<Pair>();
                nla.add(new Pair(m, la.get(0).t));
                for (int i = 1; i < la.size(); i++) {
                    nla.add(la.get(i));
                }
                ArrayList<Pair> nlb = new ArrayList<Pair>();
                for (int i = 1; i < lb.size(); i++) {
                    nlb.add(lb.get(i));
                }
                sout("added b " + lb.get(0).n, 1);
                return lb.get(0).n + lsolve(nla, nlb);
            } else {
                ArrayList<Pair> nla = new ArrayList<Pair>();
                for (int i = 1; i < la.size(); i++) {
                    nla.add(la.get(i));
                }
                ArrayList<Pair> nlb = new ArrayList<Pair>();
                nlb.add(new Pair(-m, la.get(0).t));
                for (int i = 1; i < lb.size(); i++) {
                    nlb.add(lb.get(i));
                }
                sout("added a " + la.get(0).n, 1);
                return la.get(0).n + lsolve(nla, nlb);
            }
        }
        ArrayList<Pair> nla;
        ArrayList<Pair> nlb;
        long m1;
        if (la.size() > 1) {
            nla = new ArrayList<Pair>();
            for (int i = 1; i < la.size(); i++) {
                nla.add(la.get(i));
            }
            sout("minus " + la.get(0).n, 1);
            m1 = lsolve(nla, lb);
        } else {
            m1 = 0;
        }
        long m2;
        if (lb.size() > 1) {
            nlb = new ArrayList<Pair>();
            for (int i = 1; i < lb.size(); i++) {
                nlb.add(lb.get(i));
            }
            sout("minus " + lb.get(0).n, 1);
            m2 = lsolve(la, nlb);
        } else {
            m2 = 0;
        }
        sout("m "+m2+ " "+m1,1);
        return m2 > m1 ? m2 : m1;
    }

    private static void sout(String s, int level) {
        if (LOGGING_LEVEL >= level) {
            System.out.println(s);
        }
    }


}
