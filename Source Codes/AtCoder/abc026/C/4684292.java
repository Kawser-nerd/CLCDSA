import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt() - 1;

        int[] relations = new int[n + 2];
        for (int i = 0; i < n; i++) {
            relations[i+2] = sc.nextInt();
        }
        System.out.println(getScore(1, relations));
    }

    private static int getScore(int employee, int[] relations) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < relations.length; i++) {
            if (relations[i] == employee) {
                int score = getScore(i, relations);
                max = Math.max(max, score);
                min = Math.min(min, score);
            }
        }
        if (max == Integer.MIN_VALUE && min == Integer.MAX_VALUE) {
            return 1;
        }
        return max + min + 1;
    }
}