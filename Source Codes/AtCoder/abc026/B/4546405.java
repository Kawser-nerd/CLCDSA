import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = sc.nextInt();
        }
        Arrays.sort(r);
        long R = 0;
        boolean red = true;
        for (int i = n - 1; i >= 0; i--) {
            if (red) {
                R += r[i] * r[i];
            } else {
                R -= r[i] * r[i];
            }
            red = !red;
        }
        sc.close();
        System.out.println(R * Math.PI);
    }
}