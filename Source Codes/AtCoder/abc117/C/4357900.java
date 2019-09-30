import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] a = new int[m];
        for (int i = 0; i < m; ++i) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int[] d = new int[m - 1];
        for (int i = 0; i < m - 1; ++i) {
            d[i] = a[i+1] - a[i];
        }
        Arrays.sort(d);

        int c = 0;
        for (int i = 0; i < m - n; ++i) {
            c += d[i];
        }

        System.out.println(c);
    }
}