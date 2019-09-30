import java.util.*;

public class Main {


    public static void main(String[] args) {
        new Main().execute();
    }

    public void execute() {
        Scanner sc = new Scanner(System.in);
        final int D = sc.nextInt();
        final int G = sc.nextInt() / 100;

        int[] score = new int[D];
        int[] p = new int[D];
        int[] c = new int[D];

        for (int i = 0; i < D; i++) {
            score[i] = i + 1;
            p[i] = sc.nextInt();
            c[i] = sc.nextInt() / 100;
        }

        int minTurns = Integer.MAX_VALUE;

        for (int mask = 0, bound = (1 << D); mask < bound; mask++) {
            int s = 0;
            int turns = 0;
            boolean[] ptn = getPatterns(D, mask);
            for (int i = 0; i < D; i++) {
                if (ptn[i]) {
                    s += p[i] * score[i] + c[i];
                    turns += p[i];
                }
            }
            if(s>=G){
                minTurns = Math.min(minTurns, turns);
                continue;
            }

            for (int i = (D - 1); i >= 0; i--) {
                if (ptn[i]) {
                    continue;
                }
                for (int j = 0; j < p[i] - 1; j++) {
                    s += score[i];
                    turns++;
                    if (s >= G) {
                        minTurns = Math.min(minTurns, turns);
                        break;
                    }
                }
            }
        }

        System.out.println(minTurns);
        sc.close();

    }

    private boolean[] getPatterns(int d, int mask) {
        boolean[] patterns = new boolean[d];
        for (int i = 0; i < d; i++) {
            if ((mask & (1 << i)) > 0) {
                patterns[i] = true;
            }
        }
        return patterns;
    }

}