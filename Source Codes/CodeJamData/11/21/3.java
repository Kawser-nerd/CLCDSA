import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        char[][] a = new char[n][n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        int[] played = new int[n];
        int[] won = new int[n];
        double[] wp = new double[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != '.') played[i]++;
                if (a[i][j] == '1') won[i]++;
            }
            wp[i] = won[i] * 1.0 / played[i];
        }
        double[] owp = new double[n];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            int num = 0;
            for (int j = 0; j < n; j++) if (a[i][j] != '.') {
                int w = won[j];
                int p = played[j];
                if (a[i][j] == '0') {
                    w--;
                }
                p--;
                sum += (w * 1.0 / p);
                num++;
            }
            owp[i] = sum / num;
        }
        double[] oowp = new double[n];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            int num = 0;
            for (int j = 0; j < n; j++) if (a[i][j] != '.') {
                sum += owp[j];
                num++;
            }
            oowp[i] = sum / num;
        }
        double[] rpi = new double[n];
        for (int i = 0; i < n; i++) {
            rpi[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            res.append("\n");
            res.append(rpi[i]);
        }
        return res.toString();
    }
}