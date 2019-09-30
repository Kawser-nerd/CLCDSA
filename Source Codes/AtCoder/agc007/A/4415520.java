import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int[] l = new int[h];
        int[] r = new int[h];
        for (int i = 0 ; i < h ; i++) {
            String s = sc.next();
            for (int j = 0 ; j < w ; j++) {
                if (s.substring(j, j + 1).equals("#")) {
                    l[i] = j;
                    break;
                }
            }
            for (int j = w - 1 ; j >= 0 ; j--) {
                if (s.substring(j, j + 1).equals("#")) {
                    r[i] = j;
                    break;
                }
            }
        }
        sc.close();
        boolean ans = true;
        for (int i = 0 ; i < h - 1 ; i++) {
            if (r[i] != l[i + 1]) {
                ans = false;
            }
        }

        System.out.println(ans ? "Possible" : "Impossible");
    }

}