package rueustas;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProbC {
    private static long[][] solutions;
    private static int qqs[];

    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader(new File("c.in"));
        FileWriter writer = new FileWriter(new File("c.out"));
        BufferedReader in = new BufferedReader(reader);
        String nStr = in.readLine();
        int N = Integer.parseInt(nStr);

        for (int n = 1; n <= N; n++) {
            long C = 0;
            String[] pq = in.readLine().trim().split(" ");
            int P = Integer.parseInt(pq[0]);
            int Q = Integer.parseInt(pq[1]);
            solutions = new long[102][102];
            String[] qqq = in.readLine().trim().split(" ");
            qqs = new int[Q + 2];
            qqs[0] = 0;
            qqs[Q + 1] = P + 1;
            for (int q = 1; q <= Q; q++) {
                qqs[q] = Integer.parseInt(qqq[q - 1]);
            }
            for (int q1 = 0; q1 < Q + 2; q1++) {
                for (int q2 = 0; q2 < Q + 2; q2++) {
                    solutions[q1][q2] = -1;
                }
            }
          //  System.out.println("P "+ P + " Q "+Q);
            C = solve(0, Q + 1);
            /*for (int q1 = 0; q1 < Q + 2; q1++) {
                for (int q2 = 0; q2 < Q + 2; q2++) {
                    System.out.print(solutions[q1][q2] + " ");
                }
                System.out.println();
            }
            System.out.println();*/
            writer.append("Case #" + String.valueOf(n) + ": " + C + "\r\n");
        }
        reader.close();
        writer.close();
    }

    private static long solve(int q1, int q2) {
        //System.out.print(q1 + " " + q2 + " ");
        if (solutions[q1][q2] != -1) {
           // System.out.println(solutions[q1][q2]);
            return solutions[q1][q2];
        }
        if (q1 == q2) {
         //   System.out.println(0);
            return 0;
        }
        int c0 = qqs[q2] - qqs[q1] - 2;
        if (q1 + 1 == q2) {
          //  System.out.println(c0);
            return 0;
        }

        long minC = Long.MAX_VALUE;
        for (int q = q1 + 1; q <= q2 - 1; q++) {
            long c = solve(q1, q) + solve(q, q2);
            if (c < minC) {
                minC = c;
            }
        }
        minC += c0;
        
        //System.out.println(minC);
        solutions[q1][q2] = minC;
        return minC;
    }
}