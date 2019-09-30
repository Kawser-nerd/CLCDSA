import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CoinJam {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        int J = scan.nextInt();
        String divisor = "1";
        for (int i = 0; i < N/2 - 1; i++) {
            divisor += "0";
        }
        divisor += "1";
        for (int i = 0; i < J; i++) {
            String coin = "1";
            coin += pad(Integer.toString(i, 2), N/2 - 2);
            coin += "11";
            coin += pad(Integer.toString(i, 2), N/2 - 2);
            coin += "1";
            System.out.print(coin);
            for (int base = 2; base <= 10; base++) {
                System.out.print(" ");
                System.out.print(new BigInteger(divisor, base));
//                if (Long.parseLong(coin, base) % Long.parseLong(divisor,base) != 0) {
//                    throw new AssertionError();
//                }
            }
            System.out.println();
        }
    }
    
    String pad(String s, int len) {
        String res = "";
        for (int i = s.length(); i < len; i++) {
            res += "0";
        }
        res += s;
        return res;
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ":\n");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new CoinJam().run();
    }

}
