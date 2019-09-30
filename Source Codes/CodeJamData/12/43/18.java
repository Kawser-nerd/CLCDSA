package codejam.y2012.r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Ilya Lantuh
 */
public class Task3 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int N = input.nextInt();
        int[] x = new int[N - 1];
        for (int i = 0; i < x.length; i++) {
            x[i] = input.nextInt() - 1;
        }
        for (int i = 0; i < x.length; i++) {
            for (int j = i + 1; j < x[i]; j++) {
                if (x[j] > x[i]) return "Impossible";
            }
        }
        int[] heights = new int[N];
        for (int i = 0; i < N; i++) {
            heights[i] = 10;
        }
        int checkResult;
        while ((checkResult = check(heights, x)) != 3000) {
            heights[checkResult] += 10;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < heights.length; i++) {
            sb.append(heights[i] + " ");
        }
        return sb.toString();
    }

    public static int check(int[] heights, int[] x) {
        for (int i = 0; i < x.length; i++) {
            double dh = heights[x[i]] - heights[i];
            double dl = x[i] - i;
            for (int j = i + 1; j < x[i]; j++) {
                if (j == x[i]) continue;
                double max = (double) (j - i) * dh / dl + heights[i];
                if (heights[j] >= max) return x[i];
            }
            if (x[i] == heights.length) continue;
            for (int j = x[i] + 1; j < heights.length; j++) {
                if (j == x[i]) continue;
                double max = (double) (j - i) * dh / dl + heights[i];
                if (heights[j] > max) return x[i];
            }
        }
        return 3000;
    }

}
