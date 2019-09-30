import java.io.FileReader;
import java.io.FileWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class UpAndDown {
    private static Scanner input;
    private static PrintWriter out;
    public static void main(String[] args) throws Exception {
//        input = new Scanner(System.in);
//        out = new PrintWriter(new OutputStreamWriter(System.out));
        input = new Scanner(new FileReader("B-large.in"));
        out = new PrintWriter(new FileWriter("B-large.out"));
        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveCase());
        }
        out.close();
    }
    
    public static int solveCase() {
        int n = input.nextInt();
        int[] values = new int[n];
        for(int i=0;i<n;i++) {
            values[i] = input.nextInt();
        }
        
        boolean[] done = new boolean[n];
        int res = 0;
        for(int i=0;i<n;i++) {
            int index = -1;
            for(int j=0;j<n;j++) {
                if(!done[j] && (index == -1 || values[j] < values[index]))
                    index = j;
            }
            
            int left = 0, right = 0;
            for(int j=0;j<index;j++)
                if(!done[j])
                    left++;
            for(int j=index+1;j<n;j++)
                if(!done[j])
                    right++;
            res += Math.min(left, right);
            done[index] = true;
        }
        return res;
    }

}
