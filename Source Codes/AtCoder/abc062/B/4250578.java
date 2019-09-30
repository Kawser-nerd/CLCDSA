import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();

        char[][] c = new char[h+2][w+2];
        for (int i = 0; i < h+2; i++) {
            if (i == 0 || i == h+1) {
                for (int j = 0; j < w+2; j++) {
                    c[i][j] = '#';
                }
            } else {
                String s = sc.next();
                c[i][0] = '#';
                c[i][w+1] = '#';
                for (int j = 1; j < w+1; j++) {
                    c[i][j] = s.charAt(j-1);
                }
            }
        }

        for (char[] i : c) {
            for (char j : i) {
                System.out.print(j);
            }
            System.out.println();
        }
    }
}