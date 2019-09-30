package codejam;

import java.util.Scanner;

public class A {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            String solution = new A().solve(scanner);
            System.out.println("Case #" + t + ": " + solution);
        }
    }

    int N;
    int[] P;

    private String solve(Scanner scanner) {
        N = scanner.nextInt();
        P = new int[N];
        for (int i = 0; i < N; i++) P[i] = scanner.nextInt();

        int maxP = 0;
        int maxI = -1;

        int secondMaxP = 0;
        int secondMaxI = -1;

        for (int i = 0; i < N; i++) {
            if (P[i] > maxP) {
                maxP = P[i];
                maxI = i;
            }
        }

        for (int i = 0; i < N; i++) {
            if (i == maxI) continue;
            if (P[i] > secondMaxP) {
                secondMaxP = P[i];
                secondMaxI = i;
            }
        }

        String plan = "";
        while(maxP > secondMaxP) {
            plan += (char) ('A' + maxI);
            plan += " ";
            maxP--;
        }

        for (int i = 0; i < N; i++) {
            if (i == maxI || i == secondMaxI) continue;

            while(P[i] > 0) {
                plan += (char) ('A' + i);
                plan += " ";
                P[i]--;
            }
        }

        while(maxP > 0) {
            plan += (char) ('A' + maxI);
            plan += (char) ('A' + secondMaxI);
            plan += " ";
            maxP--;
        }

        return plan;
    }

}
