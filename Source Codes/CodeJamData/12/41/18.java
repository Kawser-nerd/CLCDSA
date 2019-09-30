package codejam.y2012.r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

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
    
    static int[] d;
    static int[] l;
    static int D;

    public static String getResult() {
        int N = input.nextInt();
        d = new int[N];
        l = new int[N];
        for (int i = 0; i < N; i++) {
            d[i] = input.nextInt();
            l[i] = input.nextInt();
        }
        D = input.nextInt();
        int[][] res = new int[N][N];
        res[0][0] = d[0];
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (res[i][j] == 0) continue;
                for (int k = j+1; k < N; k++) {
                    if (d[k] > d[j] + res[i][j]) break;
                    res[j][k] = Math.max(res[j][k], Math.min(d[k] - d[j], l[k]));
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (res[i][j] == 0) continue;
                if (d[j] + res[i][j] >= D) return "YES";
            }
        }
        return "NO";
    }
    
    public static boolean isPossible(int currentVine, int currentVineLength) {
        int currentDistance = d[currentVine];
        if (currentDistance + currentVineLength >= D) return true;
        boolean res = false;
        for (int i = currentVine+1; i < d.length; i++) {
            if (d[i] > currentDistance + currentVineLength) break;
            res = res || isPossible(i, Math.min(d[i] - currentDistance, l[i]));
        }
        return res;
    }

}
