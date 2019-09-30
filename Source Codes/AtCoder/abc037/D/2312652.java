import java.util.Scanner;
 
public class Main {
    Scanner scan;
    int h, w;
 
    int[][] a;
 
    int count = 0;
    int mod = (int)1e9 + 7;
    int[][] partcount;
 
    public static void main(String args[]) {
        new Main().compute();
    }
    void compute() {
        scan = new Scanner(System.in);
 
        h = scan.nextInt();
        w = scan.nextInt();
 
        a = new int[h][w];
 
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                a[i][j] = Integer.parseInt(scan.next());
            }
        }
        partcount = new int[h][w];
 
        for (int m = 0; m < h; m++) {
            for (int n = 0; n < w; n++) {
                dfs(m, n);
                count += partcount[m][n];
                count %= mod;
            }
        }
        System.out.println(count);
    }
    void dfs(int x, int y) {
        if (partcount[x][y] == 0) {
            if (x > 0 && a[x - 1][y] > a[x][y]) {
                dfs(x - 1, y);
                partcount[x][y] += partcount[x - 1][y];
                partcount[x][y] %= mod;
            }
            if (y > 0 && a[x][y - 1] > a[x][y]) {
                dfs(x, y - 1);
                partcount[x][y] += partcount[x][y - 1];
                partcount[x][y] %= mod;
            }
            if (x<h - 1 && a[x + 1][y]>a[x][y]) {
                dfs(x + 1, y);
                partcount[x][y] += partcount[x + 1][y];
                partcount[x][y] %= mod;
            }
            if (y<w - 1 && a[x][y + 1]>a[x][y]) {
                dfs(x, y + 1);
                partcount[x][y] += partcount[x][y + 1];
                partcount[x][y] %= mod;
            }
            partcount[x][y]++;
            partcount[x][y] %= mod;
        }
    }
}