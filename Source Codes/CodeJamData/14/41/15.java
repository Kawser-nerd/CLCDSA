import java.io.FileReader;
import java.io.FileWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class DataPacking {
    private static Scanner input;
    private static PrintWriter out;
    public static void main(String[] args) throws Exception {
//        input = new Scanner(System.in);
//        out = new PrintWriter(new OutputStreamWriter(System.out));
        input = new Scanner(new FileReader("A-large.in"));
        out = new PrintWriter(new FileWriter("A-large.out"));
        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveCase());
        }
        out.close();
    }
    
    public static int solveCase() {
        int n = input.nextInt(), max = input.nextInt();
        int[] values = new int[n];
        for(int i=0;i<n;i++)
            values[i] = input.nextInt();
        
        Arrays.sort(values);
        int lower = 0, upper = n-1, res = 0;
        while(lower <= upper) {
            if(lower == upper) {
                res++;
                lower++;
            } else {
                if(values[upper] + values[lower] <= max) {
                    res++;
                    lower++;
                    upper--;
                } else {
                    res++;
                    upper--;
                }
            }
        }
        return res;
    }

}
