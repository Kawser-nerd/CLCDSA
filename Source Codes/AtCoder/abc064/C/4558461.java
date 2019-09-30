import java.util.Arrays;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        boolean[] color = new boolean[8];
        Arrays.fill(color, false);
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();

        }
        int other = 0;
        for (int i = 0; i < n; i++) {
            int rate = a[i];
            if (rate < 400) {
                color[0] = true;
            } else if (rate < 800) {
                color[1] = true;
            } else if (rate < 1200) {
                color[2] = true;
            } else if (rate < 1600) {
                color[3] = true;
            } else if (rate < 2000) {
                color[4] = true;
            } else if (rate < 2400) {
                color[5] = true;
            } else if (rate < 2800) {
                color[6] = true;
            } else if (rate < 3200) {
                color[7] = true;
            } else {
                other++;
            }

        }
        int in = 0;
        for (int i = 0; i < 8; i++) {
            if (color[i]) {
                in++;
                other++;
            }
        }
        if (in == 0) {
            in = 1;
        }
        System.out.println(in + " " + other);

        sc.close();
    }
}