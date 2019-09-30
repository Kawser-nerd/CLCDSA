import java.util.Scanner;

public class Main {
    //       6
    //     2 6 5
    //   2 2 6 6 5
    // 3 2 1 7 6 5 4

    //       6
    //     6 6 2
    //   5 6 6 2 2
    // 3 5 6 7 1 2 4

    //       2
    //     6 2 2
    //   6 6 2 2 3
    // 5 6 7 1 2 3 4

    //     2
    //   2 2 4
    // 3 2 1 4 5

    //         8
    //       8 8 3
    //     6 8 8 2 2
    //   6 6 8 8 2 2 3
    // 7 4 6 9 8 1 2 5 3

    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt() * 2 - 1, x = sc.nextInt();
        if (x == 1 || x == n) {
            System.out.println("No");
            return;
        }
        System.out.println("Yes");
        int[] ans = new int[n];
        ans[n / 2] = x;
        ans[n / 2 - 1] = x + 1;
        ans[n / 2 + 1] = x - 1;

        int idx = 1;
        for (int i = 0; i < n; i++) {
            if (idx == x - 1) {
                idx += 3;
            }
            if (i == n / 2 - 1) {
                i += 2;
                continue;
            }
            ans[i] = idx++;
        }

        for (int i = 0; i < n; i++) {
            System.out.println(ans[i]);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}