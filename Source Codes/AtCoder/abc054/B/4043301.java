import java.util.Scanner;

public class Main {

    private static int m;
    private static String[][] a;
    private static String[][] b;

    private static boolean matched(int posx, int posy) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (!a[posx + i][posy + j].equals(b[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        m = sc.nextInt();
        a = new String[n][n];
        b = new String[m][m];
        for (int i = 0; i < n; i++) {
            String[] sa = sc.next().split("");
            for (int j = 0; j < n; j++) {
                a[i][j] = sa[j];
            }
        }
        for (int i = 0; i < m; i++) {
            String[] sb = sc.next().split("");
            for (int j = 0; j < m; j++) {
                b[i][j] = sb[j];
            }
        }

        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < n - m + 1; j++) {
                if (matched(i, j)) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }

}