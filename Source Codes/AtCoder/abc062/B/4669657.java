import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();

        String[] a = new String[h];

        for (int i = 0; i < h; i++) {
            a[i] = sc.next();
        }
        sc.close();

        int cnt = 0;

        for (int i = 0; i < h + 2; i++) {
            if (!(i == 0 || i == h + 1)) {
                System.out.print("#");
                System.out.print(a[cnt]);
                System.out.print("#");
                cnt++;
            } else {
                for (int j = 0; j < w + 2; j++) {
                    System.out.print("#");
                }
            }
            System.out.println("");
        }
    }

}