import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        int N = Integer.parseInt(s);

        int[][] tbl = new int[9][9];

        int sum = 0;

        // 0-indexed
        for (int i = 0; i < tbl.length; i++) {
            for (int j = 0; j < tbl[i].length; j++) {
                tbl[i][j] = (i + 1) * (j + 1);
                sum += tbl[i][j];
            }
        }

        int x = sum - N;

        for (int i = 0; i < tbl.length; i++)
            for (int j = 0; j < tbl[i].length; j++)
                if (tbl[i][j] == x) out.println((i + 1) + " x " + (j + 1));

        out.flush();
    }
}