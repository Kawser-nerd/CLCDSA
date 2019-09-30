import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < l) {
                System.out.println(l - a[i]);
            } else if (a[i] > h) {
                System.out.println(-1);
            } else {
                System.out.println(0);
            }
        }
        sc.close();
    }
}