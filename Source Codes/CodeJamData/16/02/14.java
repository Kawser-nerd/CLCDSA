import java.io.*;
import java.util.*;

public class Pancakes {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        String S = scan.next();
        int changes = 0;
        char last = S.charAt(0);
        for (int i = 1; i < S.length(); i++) {
            char curr = S.charAt(i);
            if (curr != last) changes++;
            last = curr;
        }
        if (last == '-') changes++;
        System.out.println(changes);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Pancakes().run();
    }

}
