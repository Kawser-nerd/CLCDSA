import java.io.*;
import java.util.*;

public class Sheep {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        long N = scan.nextLong();
        if (N == 0) {
            System.out.println("INSOMNIA");
            return;
        }
        boolean[] seen = new boolean[10];
        long curr = N;
        while (true) {
            String currString = String.valueOf(curr);
            for (int i = 0; i < currString.length(); i++) {
                seen[currString.charAt(i) - '0'] = true;
            }
            if (allSeen(seen)) {
                System.out.println(curr);
                return;
            }
            curr += N;
        }
    }
    
    private boolean allSeen(boolean[] seen) {
        for (int i = 0; i <= 9; i++) {
            if (!seen[i]) return false;
        }
        return true;
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Sheep().run();
    }

}
