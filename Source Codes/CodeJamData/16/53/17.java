import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class RebelAgainstTheEmpire1 {

    static int n, s;
    static int[] x, y, z;
    static boolean[][] g;
    static int[] cand;
    static boolean[] visited;

    static double sqr(double a) {
        return a * a;
    }

    static int sqr(int a) {
        return a * a;
    }

    static int dist2(int i, int j) {
        return sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]);
    }

    static boolean dfs(int u) {
        visited[u] = true;
        if (u == 1) return true;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v])
                if (dfs(v)) return true;
        return false;
    }

    static boolean isok(int threshold) {
        g = new boolean[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = dist2(i, j) <= threshold;
        visited = new boolean[n];
        return dfs(0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner cin = new Scanner(new File("C-small-attempt1.in"));
        PrintStream cout = new PrintStream("C-small-attempt1.out");
//        Scanner cin = new Scanner(new File("A-large.in"));
//        PrintStream cout = new PrintStream("A-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;
            StringBuilder ans = new StringBuilder();

            n = cin.nextInt();
            s = cin.nextInt();
            x = new int[n];
            y = new int[n];
            z = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = cin.nextInt();
                y[i] = cin.nextInt();
                z[i] = cin.nextInt();
                cin.nextLine();
            }

            cand = new int[n * n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cand[i * n + j] = dist2(i, j);
            Arrays.sort(cand);

            int left = -1, right = n * n - 1;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (isok(cand[mid])) right = mid;
                else left = mid;
            }
            ans.append(String.format("%.10f", Math.sqrt(cand[right])));

            cout.printf("Case #%d: %s%n", _case, ans.toString());
        }

        cin.close();
        cout.close();
    }
}
