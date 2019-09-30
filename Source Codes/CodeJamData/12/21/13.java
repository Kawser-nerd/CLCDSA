
import java.io.*;
import java.util.*;

public class Safety {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int n = scan.nextInt();
        int[] s = new int[n];
        int origx = 0;
        for(int i = 0; i < n; i++) {
            s[i] = scan.nextInt();
            origx += s[i];
        }
        int twox = 2 * origx; // nb
        double[] res = new double[n];
        int left = n;
        for(int i = 0; i < n; i++) {
            res[i] = -1;
        }
        while(left > 0) {
            double scoreToGet = ((double)twox) / left;
            boolean foundSureWinner = false;
            for(int i = 0; i < n; i++) {
                if(res[i]>=0) continue;
                if(s[i]>scoreToGet) {
                    res[i] = 0;
                    twox -= s[i];
                    foundSureWinner = true;
                    left--;
                }
            }
            if(!foundSureWinner) break;
        }
        if(left > 0) {
            for(int i = 0; i < n; i++) {
                if(res[i]<0) {
                    res[i] = 100.0 * ( ((double)twox)/left - s[i] ) / origx;
                    //System.err.println(" " + left + " " + twox + " " + s[i] + " " + res[i]);
                    if(res[i] < 0) res[i] = 0;
                    if(res[i] > 100) res[i] = 100;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            out.print(res[i]);
            if(i+1<n) out.print(" ");
        }
        out.println();
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Safety().run();
    }

}
