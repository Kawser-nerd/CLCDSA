import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] c = new int[4][4];

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                c[i][j] = sc.nextInt();
            }
        }

        if (c[2][1] - c[1][1] == c[2][2] - c[1][2] &&
                c[2][1] - c[1][1] == c[2][3] - c[1][3] &&
                c[3][1] - c[1][1] == c[3][2] - c[1][2] &&
                c[3][1] - c[1][1] == c[3][3] - c[1][3]) {
            out.println("Yes");
        } else {
            out.println("No");
        }
    }
}