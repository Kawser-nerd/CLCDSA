import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(sc.next()) - 1;
        }

        boolean[] b = new boolean[n];
        int i = 0;
        int cnt = 0;

        for ( ; !b[i] && i != 1; ++cnt) {
            b[i] = true;
            i = a[i];
        }

        if (i == 1) {
            System.out.println(cnt);
        } else {
            System.out.println(-1);
        }
    }
}