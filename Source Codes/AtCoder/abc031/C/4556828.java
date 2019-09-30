import java.util.Arrays;
import java.util.Scanner;

class Main {
    static int[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        // b ? b?????????????????????????
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            int taka = 0;
            int aoki = Integer.MIN_VALUE;
            int tmp = 0;
            int ao = 0;
            for (int j = 0; j < n; j++) {
                // j ? ?????????
                if (i == j) {
                    continue;
                } else if (i < j) {
                    tmp = culc(i, j);
                    ao = culc(i + 1, j);
                } else {
                    tmp = culc(j, i);
                    ao = culc(j + 1, i);
                }
                if (aoki < ao) {

                    aoki = ao;
                    taka = tmp;
                }

            }
            b[i] = taka;
        }
        Arrays.sort(b);
        System.out.println(b[n - 1]);
        sc.close();

    }

    public static int culc(int pos, int pos2) {
        int ans = 0;
        for (int i = pos; i <= pos2; i++) {
            ans += a[i];
            i++;
        }
        return ans;
    }
}