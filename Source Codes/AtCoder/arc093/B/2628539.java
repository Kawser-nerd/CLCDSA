import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int a = sc.nextInt();
        int b = sc.nextInt();

        char data[][] = new char[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                data[i][j] = (i / 50 == 0 ? '#' : '.');
            }
        }

        for (int i = 0; i < a - 1; i++) {
            data[2 * (i / 50)][2 * (i % 50)] = '.';
        }
        for (int i = 0; i < b - 1; i++) {
            data[2 * (i / 50) + 51][2 * (i % 50)] = '#';
        }

        System.out.println("100 100");
        for (int i = 0; i < 100; i++) {
            System.out.println(new String(data[i]));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}