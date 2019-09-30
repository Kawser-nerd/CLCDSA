import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
        int E = sc.nextInt();
        int F = sc.nextInt();

        Set<Integer> waterSet = new HashSet<>();
        Set<Integer> sugarSet = new HashSet<>();
        createSugar(sugarSet, C, D, F);
        createWater(waterSet, A, B, F);

        double maxRatio = -1;
        int resultSugar = -1;
        int resultWater = -1;

        for (int water : waterSet) {
            for (int sugar : sugarSet) {
                if ((water + sugar) <= F && sugar <= (water / 100) * E) {

                    double ratio = ((double) (100 * sugar)) / (water + sugar);
                    if (ratio > maxRatio) {
                        maxRatio = ((double)(100 * sugar)) / (water + sugar);
                        resultSugar = sugar;
                        resultWater = water;
                    }
                }
            }
        }

        System.out.println(resultSugar + resultWater + " " + resultSugar);


    }

    private static void createWater (Set<Integer> waterSet, int A, int B, int F) {
        for (int i = 0; i < F ; i++) {
            for (int j = 0; j < F; j++) {
                int water = A * 100 * i + B * 100 * j;
                if (water != 0 && water < F) waterSet.add(water);
            }
        }
    }

    private static void createSugar(Set<Integer> sugarSet, int C, int D, int F) {
         for (int i = 0; i < F; i++) {
            for (int j = 0; j < F; j++) {
                int sugar = C * i + D * j;
                if (sugar < F) sugarSet.add(sugar);
            }
        }
    }

}