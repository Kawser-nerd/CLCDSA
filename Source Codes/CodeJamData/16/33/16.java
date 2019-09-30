package codejam;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.print("Case #" + t + ": ");
            String solution = new C().solve(scanner);
        }
    }

    int J, P, S, K;

    private String solve(Scanner scanner) {
        J = scanner.nextInt();
        P = scanner.nextInt();
        S = scanner.nextInt();
        K = scanner.nextInt();

        int M = Math.min(S, K);

        List<int[]> list = new ArrayList<>();
        for (int j = 1; j <= J; j++) {
            for (int p = 1; p <= P; p++) {
                for (int s = 1; s <= M; s++) {
                    int sh = (j + p + s) % S + 1;
                    list.add(new int[]{j, p, sh});
                }
            }
        }

        System.out.println(list.size());
        for (int[] c : list) {
            for (int i : c) {
                System.out.print(i + " ");
            }
            System.out.println("");
        }
        return null;
    }

}
