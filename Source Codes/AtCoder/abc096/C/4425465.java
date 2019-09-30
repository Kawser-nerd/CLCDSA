import java.util.Scanner;

public class Main {

    private static String[][] s;


    private static boolean hasNeighbor(int h, int w) {
        return (h != 0 && "#".equals(s[h - 1][w]))
                || (h != s.length - 1 && "#".equals(s[h + 1][w]))
                || (w != 0 && "#".equals(s[h][w - 1]))
                || (w != s[h].length - 1 && "#".equals(s[h][w + 1]));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        s = new String[h][w];
        for (int i = 0; i < h; i++) {
            s[i] = sc.next().split("");
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (".".equals(s[i][j])) {
                    continue;
                }
                if (!hasNeighbor(i, j)) {
                    System.out.println("No");
                    return;
                }
            }
        }
        System.out.println("Yes");
    }

}