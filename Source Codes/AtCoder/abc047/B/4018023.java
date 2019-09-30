import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            a[i] = sc.nextInt();
        }

        int ws = 0;
        int we = w;
        int hs = 0;
        int he = h;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (x[i] > ws) {
                    ws = x[i];
                }
            } else if (a[i] == 2) {
                if (x[i] < we) {
                    we = x[i];
                }
            } else if (a[i] == 3) {
                if (y[i] > hs) {
                    hs = y[i];
                }
            } else if (a[i] == 4) {
                if (y[i] < he) {
                    he = y[i];
                }
            }
            if (we - ws < 0 || he - hs < 0) {
                System.out.println(0);
                return;
            }
        }
        System.out.println((we - ws) * (he - hs));
    }

}