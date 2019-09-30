import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] values = new int[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                values[i][j] = sc.nextInt();
            }
        }

        boolean ok = false;
        for (int i = 0; i < 101; i++) { // a1
            for (int j = 0; j < 101; j++) { // a2
                for (int k = 0; k < 101; k++) { // a3
                    int b1 = values[0][0] - i;
                    int b2 = values[0][1] - i;
                    int b3 = values[0][2] - i;
                    if (b1 < 0 || b2 < 0 || b3 < 0) continue;
                    if ((values[1][0] == j + b1 && values[1][1] == j + b2 && values[1][2] == j + b3) &&
                            (values[2][0] == k + b1 && values[2][1] == k + b2 && values[2][2] == k + b3)) {
                        ok = true;
                    }
                }
            }
        }

        System.out.println(ok ? "Yes" : "No");
    }
}