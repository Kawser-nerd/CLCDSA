import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();

//        ArrayList<ArrayList> a = new ArrayList<>();

        char a[][] = new char[102][102];

        String str = "";
        for (int i = 0; i < h + 2; i++) {
            if (i != 0 && i != h + 1) {
                str = sc.next();
            }
            for (int j = 0; j < w + 2; j++) {

                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) a[i][j] = '#';
                else a[i][j] = str.charAt(j - 1);
            }
        }

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                System.out.print(a[i][j]);
                if (j == w + 1) System.out.println();
            }
        }
    }
}