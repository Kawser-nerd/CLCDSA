import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    Scanner in;
    BufferedReader br;
    PrintWriter out;
    
    public void run() throws Exception {
        in = new Scanner(System.in);
        // br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int tests = in.nextInt(); // Integer.parseInt(br.readLine());
        for (int test = 1; test <= tests; test++) {
            TreeSet<BigInteger> hs = new TreeSet<BigInteger>();
            int nnn = in.nextInt();
            for (int i = 0; i < nnn; i++) hs.add(in.nextBigInteger());
            int n = hs.size();
            BigInteger[] a = new BigInteger[n];
            nnn = 0;
            for (BigInteger x : hs) a[nnn++] = x;
            BigInteger g = a[1].subtract(a[0]);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    g = g.gcd(a[j].subtract(a[i]));
                }
            }
            BigInteger mn = BigInteger.valueOf(10).pow(100);
            BigInteger g1 = g.subtract(BigInteger.ONE);
            for (int i = 0; i < n; i++) {
                BigInteger cur = a[i].add(g1).divide(g).multiply(g).subtract(a[i]);
                // out.println(": " + cur);
                mn = mn.min(cur);
            }
            out.println("Case #" + test + ": " + mn);
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        new Main().run();
    }
    
}
