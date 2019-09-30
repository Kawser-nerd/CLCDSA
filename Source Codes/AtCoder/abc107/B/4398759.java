import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String[][] a = new String[h][w];
        boolean[] row = new boolean[h];
        boolean[] column = new boolean[w];
        for (int i = 0; i < h; i++) {
            a[i] = sc.next().split("");
            row[i] = false;
        }
        for (int i = 0; i < w; i++) {
            column[i] = false;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if ("#".equals(a[i][j])) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            if (!row[i]) {
                continue;
            }
            StringJoiner sj = new StringJoiner("");
            for (int j = 0; j < w; j++) {
                if (!column[j]) {
                    continue;
                }
                sj.add(a[i][j]);
            }
            System.out.println(sj.toString());
        }
    }

}