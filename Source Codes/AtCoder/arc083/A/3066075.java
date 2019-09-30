import java.util.Scanner;

public class Main {
    private static boolean isGreater(int p, int q, int pp, int qq) {
        p *= qq;
        pp *= q;
        return p > pp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
        int E = sc.nextInt();
        int F = sc.nextInt();

        int ansX = 100 * A;
        int ansY = 0;
        int maxP = 0;
        int maxQ = 1;

        for (int ai = 0; ai * 100 <= F; ai += A) {
            int a = ai * 100;
            for (int bi = 0; a + 100 * bi <= F; bi += B) {
                int b = bi * 100;
                for (int c = 0; a + b + c <= F; c += C) {
                    for (int d = 0; a + b + c + d <= F; d += D) {
                        if ( (ai + bi) * E < c + d ) {
                            continue;
                        }
                        int water = a + b;
                        int sugar = c + d;
                        if ( isGreater(sugar * 100, water + sugar, maxP, maxQ) ) {
                            maxP = sugar * 100;
                            maxQ = water + sugar;
                            ansX = water + sugar;
                            ansY = sugar;
                        }
                    }
                }
            }
        }

        System.out.println(ansX + " " + ansY);
    }
}