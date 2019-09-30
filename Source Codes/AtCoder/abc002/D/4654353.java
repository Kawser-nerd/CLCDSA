import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.max;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), m = sc.nextInt();
        boolean[][] relation = new boolean[n][n];

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            x--;
            y--;
            relation[x][y] = relation[y][x] = true;
        }

        int ans = 0;

        for (int i = 0; i < (2 << n); i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    list.add(j);
                }
            }

            boolean flag = true;
            for (int j = 0; j < list.size(); j++) {
                for (int k = 0; k < list.size(); k++) {
                    int x = list.get(j);
                    int y = list.get(k);
                    if (x == y) {
                        continue;
                    }
                    if ((((i >> x) & 1) == 1) && (((i >> y) & 1) == 1) && !relation[x][y]) {
                        flag = false;
                    }
                }
            }

            if (flag) {
                ans = max(ans, list.size());
            }
        }

        System.out.println(ans);
    }
}