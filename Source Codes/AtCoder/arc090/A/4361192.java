import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] candies = new int[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                candies[i][j] = sc.nextInt();
            }
        }
        int max = maxCandies(candies);
        System.out.println(max);
    }

    /**
     * Approach:
     * We will loop through `candies` & keep the aggregate number of candies
     * on the top row
     *
     * We will also calculate the diff of the candy on the bottom row vs. the next candy on the top row.
     * We will keep an aggregate of this diff - whenever the diff is below 0, we will set it to 0
     *
     * If it is positive, it will keep track of our score if we had switched to the bottom row.
     * If it is zero, it is better to stay on the top row throughout.
     *
     * The max is just the sum of the aggregate of top row plus the aggregate delta.
     *
     */
    private static int maxCandies(int[][] candies) {

        int topSum = 0; // Sum of staying on the top row
        int bottomDelta = 0; // Delta for switching to the bottom row
        int i = 0;
        for ( ; i < candies[0].length - 1; i++) {
           bottomDelta += candies[1][i] - candies[0][i + 1];
           if (bottomDelta < 0) bottomDelta = 0;
           topSum += candies[0][i];
        }
        topSum += candies[0][i] + candies[1][i];
        return topSum + bottomDelta;
    }

}