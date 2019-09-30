import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Alien {
    public static void main(String[] args) throws IOException {
        File input = new File("A-large.in");
        Scanner in = new Scanner(input);
        File output = new File("A-large.out");
        PrintWriter out = new PrintWriter(output);
        
        int wordLength = in.nextInt();
        int wordCount = in.nextInt();
        int testCount = in.nextInt();
        
        Set<String> dictionary = new HashSet<String>();
        for (int i = 0; i < wordCount; i++) {
            dictionary.add(in.next());
        }
        
        for (int i = 1; i <= testCount; i++) {
            long solution = solve(dictionary, in.next());
            out.format("Case #%d: %d\n", i, solution);
        }
        
        out.close();
        
        System.err.println("Done!");
    }
    
    public static long solve(Set<String> dict, String pattern) {
        StringBuilder buffer = new StringBuilder();
        boolean inGroup = false;
        for (char c : pattern.toCharArray()) {
            if (c == '(') {
                inGroup = true;
            } else if (c == ')') {
                inGroup = false;
            } else if (inGroup &&
                    buffer.charAt(buffer.length() - 1) != '(') {
                buffer.append('|');
            }
            buffer.append(c);
        }
        
        Pattern regex = Pattern.compile(buffer.toString());
        
        long total = 0;
        for (String w : dict) {
            if (regex.matcher(w).matches()) {
                total++;
            }
        }
        return total;
    }
}