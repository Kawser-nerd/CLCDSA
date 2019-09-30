import java.io.*;
import java.util.*;

public class Welcome {
    
    public static void main(String[] args) throws IOException {
        File input = new File("C-large.in");
        Scanner in = new Scanner(input);
        File output = new File("C-large.out");
        PrintWriter out = new PrintWriter(output);
        
        int testCount = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= testCount; i++) {
            String str = in.nextLine();
            out.format("Case #%d: %04d\n", i, solve(str));
        }
        out.close();
        System.err.println("Done!");
    }
    
    private static String key = "welcome to code jam";
    private static long[][] matrix;
    
    public static long solve(String input) {
        // Given chars I->end and J->end, how many ways?
        matrix = new long[input.length() + 1][key.length() + 1];
        for (int i = input.length(); i >= 0 ; i--) {
            matrix[i][key.length()] = 1;
        }
        // And there are zero matches when the corpus is empty
        // and the key is not, so we're OK.
        
        for (int i = input.length() - 1; i >= 0 ; i--) {
            for (int j = key.length() - 1; j >= 0; j--) {
                if (key.charAt(j) == input.charAt(i)) {
                    matrix[i][j] = matrix[i + 1][j + 1] + matrix[i + 1][j];
                    matrix[i][j] %= 10000;
                } else {
                    // # of matches if we don't consume the latest
                    // key character
                    matrix[i][j] = matrix[i + 1][j];
                }
            }
        }
        
        return matrix[0][0];
    }
    
    
}