import java.io.*;
import java.util.*;

public class Fractiles {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int K = scan.nextInt();
        int C = scan.nextInt();
        int S = scan.nextInt();
        if (S * C < K) {
            System.out.println(" IMPOSSIBLE");
            return;
        }
        int digit = 0;
        while (digit < K) {
            long res = 0;
            for (int i = 0; i < C; i++) {
                res *= K;
                if (digit < K) res += digit;
                digit++;
            }
            System.out.print(" ");
            System.out.print(res + 1);
        }
        System.out.println();
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ":");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Fractiles().run();
    }

}
