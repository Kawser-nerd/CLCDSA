import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int a[] = new int[N];
        int sum = 0;
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }
        if (sum == 0) {
            System.out.println(0);
            return;
        }

        if (sum % N != 0) {
            System.out.println(-1);
            return;
        }

        int deficiency = 0;
        int needed = sum / N;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            deficiency += a[i] - needed;
            if (deficiency != 0) {
                ++ans;
            }
        }
        System.out.println(ans);

    }
}