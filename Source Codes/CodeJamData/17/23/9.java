import java.io.*;
import java.util.Scanner;

public class ProblemC {
//    String FILENAME = "problemC_example";
//    String FILENAME = "problemC_small";

    String FILENAME = "problemC_large";

    public String getInFileName() {
        return FILENAME + ".in";
    }

    public String getOutFileName() {
        return FILENAME + ".out";
    }

    public static void main(String[] args) throws Exception {
        new ProblemC();
    }

    public ProblemC() throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
                getOutFileName())));
        Scanner scan = new Scanner(in);
        int tests = scan.nextInt();
        long INF = 1_000_000_000_000L;
        for (int test = 0; test < tests; test++) {
            int n = scan.nextInt();
            int nrPairs = scan.nextInt();
            int[] maxDist = new int[n];
            int[] speed = new int[n];
            for (int i = 0; i < n; i++) {
                maxDist[i] = scan.nextInt();
                speed[i] = scan.nextInt();
            }
            long[][] dist = new long[n][n];
            for ( int i = 0; i < n; i++)
                for ( int j = 0; j < n; j++) {
                    dist[i][j] = scan.nextInt();
                    if ( dist[i][j] < 0 ) dist[i][j] = INF;
                }
            for ( int k = 0; k < n; k++ ) {
                for ( int i = 0; i < n; i++)
                    for ( int j = 0; j < n; j++) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
            }
            double[][] time = new double[n][n];
            for ( int i = 0; i < n; i++)
                for ( int j = 0; j < n; j++) {
                    time[i][j] = dist[i][j] <= maxDist[i] ? dist[i][j]*1.0/speed[i] : INF;
                }
            for ( int k = 0; k < n; k++ ) {
                for ( int i = 0; i < n; i++)
                    for ( int j = 0; j < n; j++) {
                        time[i][j] = Math.min(time[i][j], time[i][k] + time[k][j]);
                    }
            }


            StringBuilder sb = new StringBuilder();
            sb.append(String.format("Case #%d: ", test + 1));
            for ( int i = 0; i < nrPairs; i++) {
                int u = scan.nextInt() - 1;
                int v = scan.nextInt() - 1;
                sb.append(String.format("%.9f ", time[u][v]));
            }

            String resultStr = sb.toString();
            // add answer here

            System.out.println(resultStr);
            out.println(resultStr);
        }
        out.close();
        System.out.println("*** in file =  " + getInFileName());
        System.out.println("*** out file = " + getOutFileName());
    }
}
