import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextInt();
        }
        int max = -100000;
        for (int i = 0 ; i < n ; i++) {
            int bmax = -100000;
            int amax = -100000;
            for (int j = 0 ; j < n ; j++) {
                int ap = 0;
                int bp = 0;
                if (i != j) {
                    for (int k = Math.min(i, j); k <= Math.max(i, j); k++) {
                        if ((k - Math.min(i, j)) % 2 == 0) {
                            ap += a[k];
                        } else {
                            bp += a[k];
                        }
                    }
                    if (bp > bmax) {
                        bmax = bp;
                        amax = ap;
                    }
                }

            }
            max = Math.max(max, amax);
        }
        System.out.println(max);

    }

}