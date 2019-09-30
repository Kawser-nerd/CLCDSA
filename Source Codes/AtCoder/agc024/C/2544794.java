import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[n - i - 1] = sc.nextInt();
        }

        long ret = 0;
        for (int i = 0; i < n-1; i++) {
            int tmp = a[i] - a[i+1];
            if(tmp == 1) {
                ret++;
            }
            else if(tmp > 1) {
                System.out.println(-1);
                return;
            }
            else {
                ret += a[i];
            }
        }
        if(a[n-1] != 0) {
            System.out.println(-1);
        }
        else {
            System.out.println(ret);
        }
    }
}