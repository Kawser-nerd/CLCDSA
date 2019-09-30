import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int J = in.nextInt();
            int found = 0;
            System.out.format("Case #%d:\n", t);
            for (long i = 0; i < 1L << (N-2); i++) {
                String s = Long.toString(i, 2);
                while (s.length() < N-2)
                    s = "0" + s;
                String rep = "1" + s + "1";
                boolean valid = true;
                ArrayList<Integer> factors = new ArrayList<Integer>();
                for (int b = 2; b <= 10; b++) {
                    BigInteger bi = new BigInteger(rep, b);
                    if (bi.isProbablePrime(100)) {
                        valid = false;
                        break;
                    }
                    boolean foundFactor = false;
                    for (int j = 2; j < 10000; j++) {
                        if (bi.mod(BigInteger.valueOf(j)).equals(BigInteger.ZERO)) {
                            foundFactor = true;
                            factors.add(j);
                            break;
                        }
                    }
                    if (!foundFactor) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    System.out.print(rep);
                    for (int f : factors)
                        System.out.format(" %d", f);
                    System.out.println();
                    found++;
                    if (found == J) {
                        break;
                    }
                }
            }
        }
    }
}
