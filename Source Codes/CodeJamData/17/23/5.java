package year2017.round1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class PonyExpress {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("C-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int Q = in.nextInt();
            double[] E = new double[N];
            double[] S = new double[N];
            for (int n=0; n<N; n++) {
                E[n] = in.nextDouble();
                S[n] = in.nextDouble();
            }
            long[][] D = new long[N][N];
            for (int from=0; from<N; from++) {
                for (int to=0; to<N; to++) {
                    D[from][to] = in.nextLong();
                }
            }
            // 1st Floyd-Warshall
            for (int k=0; k<N; k++) {
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        if (i != j && D[i][k] != -1 && D[k][j] != -1) {
                            long newDist = D[i][k] + D[k][j];
                            if (D[i][j] == -1 || D[i][j] > newDist) {
                                D[i][j] = newDist;
                            }
                        }
                    }
                }
            }
            
            double[][] dist = new double[N][N];
            for (int from=0; from<N; from++) {
                for (int to=0; to<N; to++) {
                    if (from != to && D[from][to] != -1 && D[from][to] <= E[from]) {
                        dist[from][to] = D[from][to] / (double) S[from];
                    } else {
                        dist[from][to] = Double.MAX_VALUE;
                    }
                }
            }
            
            // 2nd Floyd-Warshall
            for (int k=0; k<N; k++) {
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        if (i != j) {
                            double newDist = dist[i][k] + dist[k][j];
                            if (dist[i][j] == -1 || dist[i][j] > newDist) {
                                dist[i][j] = newDist;
                            }
                        }
                    }
                }
            }

            StringBuilder answer = new StringBuilder();
            for (int q=0; q<Q; q++) {
                int U = in.nextInt() - 1;
                int V = in.nextInt() - 1;
                answer.append(' ').append(dist[U][V]);
            }
            
            out.println("Case #"+(t+1)+":" + answer);
        }

        out.close();
    }
    
}
