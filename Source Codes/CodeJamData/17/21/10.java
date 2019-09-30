

import java.io.*;
import java.util.*;

public class Steed {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    long D;
    int N;
    long[] K;
    long[] S;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        D = scan.nextLong();
        N = scan.nextInt();
        K = new long[N];
        S = new long[N];
        for (int i = 0; i < N; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            K[i] = scan.nextLong();
            S[i] = scan.nextLong();
        }
        double longestTimeToDest = 0;
        for (int i = 0; i < N; i++) {
            double thisTimeToDest = ((double)(D - K[i]))/S[i];
            if (thisTimeToDest > longestTimeToDest) longestTimeToDest = thisTimeToDest;
        }
        System.out.println(D / longestTimeToDest);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Steed().run();
    }

}
