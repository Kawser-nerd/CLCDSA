import java.util.Scanner;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(), b = in.nextInt();
        boolean[][] field = new boolean[100][100];
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 100; j++) {
                field[i][j] = true;
            }
        }
        for (int i = 0; i < a - 1; i++) {
            int x = i / 50 * 2;
            int y = i % 50 * 2;
            field[x][y] = false;
        }
        for (int i = 0; i < b - 1; i++) {
            int x = i / 50 * 2 + 51;
            int y = i % 50 * 2;
            field[x][y] = true;
        }
        System.out.println("100 100");
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                System.out.print(field[i][j] ? '#' : '.');
            }
            System.out.println();
        }
    }
}