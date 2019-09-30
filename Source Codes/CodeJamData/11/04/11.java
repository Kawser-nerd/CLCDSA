package D;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class GoroSort {
    private static double[] d = new double[1010];

    public static void main(String[] args) throws IOException {
//        solveAll(1000);
        BufferedReader reader = new BufferedReader(new FileReader("src/D/D-large.in"));
        String s = reader.readLine();
        int t = Integer.parseInt(s);
        PrintWriter writer = new PrintWriter("src/D/output.txt");
        for (int i = 0; i < t; i++) {
            s = reader.readLine();
            int n = Integer.parseInt(s);
            int[] a = new int[n];
            s = reader.readLine();
            String[] ss = s.split("\\s+");
            for (int j = 0; j < n; j++) {
                a[j] = Integer.parseInt(ss[j]) - 1;
            }
            double ans = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] < 0) continue;
                int cycle = 1;
                int k = a[j];
                while (k != j) {
                    int temp = k;
                    k = a[k];
                    a[temp] = -1;
                    cycle++;
                }
                ans += solveCycle(cycle);
            }
            writer.println("Case #" + (i + 1) + ": " + ans);
        }
        writer.close();
    }

    private static double solveCycle(int cycle) {
        if (cycle < 2) {
            return 0;
        }
        return 1 + solveAll(cycle);
    }

    private static double solveAll(int all) {
        if (all < 2) {
            return 0;
        }
        if (d[all] > 0) {
            return d[all];
        }
        double ans = 0;
        for (int i = 1; i < all; i++) {
            ans += 1.0 / all * (solveCycle(i) + solveAll(all - i));
        }
        ans = (ans * all + 1) / (all - 1);
        d[all] = ans;
        return ans;
    }
}
