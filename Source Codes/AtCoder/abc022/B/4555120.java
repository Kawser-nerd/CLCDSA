import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            int b = a[i];
            for (int j = 0; j < i; j++) {
                int c = a[j];
                if (b == c) {
                    ans++;
                    // System.out.println(b);
                    break;

                }
            }
        }
        System.out.println(ans);
        sc.close();
    }
}