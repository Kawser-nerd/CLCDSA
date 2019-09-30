import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String[][] s = new String[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                s[i][j] = sc.next();
            }
        }
        for (int i = 3; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                System.out.print(s[i][j]);
                if (j != 0) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}