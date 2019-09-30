import java.io.*;
import java.util.Scanner;


public class ProblemA {
//    String FILENAME = "problemA_example";
//    String FILENAME = "problemA_small";

    String FILENAME = "problemA_large";

    public String getInFileName() {
        return FILENAME + ".in";
    }

    public String getOutFileName() {
        return FILENAME + ".out";
    }

    public static void main(String[] args) throws Exception {
        new ProblemA();
    }

    public ProblemA() throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
                getOutFileName())));
        Scanner scan = new Scanner(in);
        int tests = scan.nextInt();
        for (int test = 0; test < tests; test++) {
            int d = scan.nextInt();
            int n = scan.nextInt();
            double maxTime = 0.0;
            for ( int i = 0; i < n; i++ ) {
                int k = scan.nextInt();
                double s = scan.nextInt();
                double time = (d - k)/s;
                maxTime = Math.max(maxTime, time);
            }
            String resultStr = String.format("Case #%d: %.9f", test + 1, d/maxTime);
            // add answer here

            System.out.println(resultStr);
            out.println(resultStr);
        }
        out.close();
        System.out.println("*** in file =  " + getInFileName());
        System.out.println("*** out file = " + getOutFileName());
    }
}
