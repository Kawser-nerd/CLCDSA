import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.math.*;
import java.util.*;

class Main {
    void run() {
        int T = cin.nextInt();
        for (int nT = 1; nT <= T; ++nT) {
            BigInteger r = cin.nextBigInteger();
            BigInteger t = cin.nextBigInteger();
            BigInteger low = BigInteger.ONE, high = t.divide(r).add(BigInteger.ONE);
            BigInteger res = BigInteger.ONE;
            while (low.compareTo(high) < 0) {
                BigInteger mid = (low.add(high)).divide(BigInteger.valueOf(2));
                BigInteger need = r.multiply(mid).multiply(BigInteger.valueOf(2));
                BigInteger need2 = BigInteger.ONE.add(mid.subtract(BigInteger.ONE).multiply(BigInteger.valueOf(4)));
                need2 = need2.add(BigInteger.ONE);
                need2 = need2.multiply(mid);
                need2 = need2.divide(BigInteger.valueOf(2));
                //if (mid.equals(BigInteger.ZERO)) need2 = BigInteger.ZERO;
                need = need.add(need2);
                if (need.compareTo(t) <= 0) {
                    res = mid;
                    low = mid.add(BigInteger.ONE);
                } else {
                    high = mid;
                }
            }
            System.out.println("Case #" + nT + ": " + res);
        }
    }
    public static void main(String[] argv) {
        try {
            System.setIn(new FileInputStream("A-large.in"));
            System.setOut(new PrintStream("A2.out"));
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
        Main solved = new Main();
        solved.run();
    }
    Scanner cin = new Scanner(System.in);
}