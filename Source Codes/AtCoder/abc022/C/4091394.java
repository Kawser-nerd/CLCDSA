import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int[][] r = new int[300][300];
    static int inf = 100000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < 300; i++) {
            for (int j = 0; j < 300; j++) {
                if (i != j) {
                    r[i][j] = inf;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            r[u][v] = r[v][u] = sc.nextInt();
        }
        //1???????????????
        List<Integer> vList = new ArrayList<>();
        int[] vLength = new int[300];
        for (int i = 1; i < 300; i++) {
            if (r[0][i] != inf) {
                vList.add(i);
                vLength[i] = r[0][i];
            }
        }
        for (int i = 1; i < 300; i++) {
            r[0][i] = r[i][0] = inf;
        }
        warshall_floyd();
        int minLength = inf;
        for (int i = 0; i < vList.size(); i++) {
            for (int j = 0; j < vList.size(); j++) {
                if (i < j) {
                    if (r[vList.get(i)][vList.get(j)] != inf) {
                        minLength = Math.min(minLength,
                                r[vList.get(i)][vList.get(j)] + vLength[vList.get(i)] + vLength[vList.get(j)]);
                    }

                }
            }
        }

        if (minLength == inf) {
            System.out.println(-1);
        } else {
            System.out.println(minLength);
        }

    }

    static void warshall_floyd() {
        for (int k = 0; k < 300; k++) {
            for (int i = 0; i < 300; i++) {
                for (int j = 0; j < 300; j++) {
                    r[i][j] = Math.min(r[i][j], r[i][k] + r[k][j]);
                }
            }
        }
    }

}