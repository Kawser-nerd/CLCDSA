import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();

        char[][] c = new char[h*2][w];
        for (int i = 0; i < h; i++) {
            char[] s = sc.next().toCharArray();
            c[i*2] = s;
            c[i*2+1] = s;
        }

        for (char[] s : c) {
            for (char s1 : s)
                System.out.print(s1);
            System.out.println();
        }
    }
}