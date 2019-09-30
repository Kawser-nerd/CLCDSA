import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] > max) {
                max = a[i];
            }
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
            if (b[i] > max) {
                max = b[i];
            }
        }
        int time = 0;
        int apos = 0;
        int bpos = 0;
        boolean flag = true;
        boolean nowa = true;
        int ans = 0;
        while (time <= max) {
            if (nowa) {
                for (int i = apos; i < n; i++) {
                    if (a[i] >= time) {
                        time = a[i] + x;
                        nowa = false;
                        apos = i;
                        break;
                    } else {
                        if (i == n - 1) {
                            System.out.println(ans);
                            return;
                        }
                    }
                }
            } else {
                for (int j = bpos; j < m; j++) {
                    if (b[j] >= time) {
                        time = b[j] + y;
                        ans++;
                        nowa = true;
                        bpos = j;
                        break;
                    } else {
                        if (j == m - 1) {
                            System.out.println(ans);
                            return;
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}