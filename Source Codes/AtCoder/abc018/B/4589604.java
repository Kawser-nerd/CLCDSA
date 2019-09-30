import java.util.Scanner;
import java.lang.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(s.substring(a[i] - 1, b[i]));

            sb.reverse();
            s = s.substring(0, a[i] - 1) + sb + s.substring(b[i]);

            sb.setLength(0);
        }
        System.out.println(s);
        sc.close();
    }
}