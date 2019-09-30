import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int nAsInt;
    static int count;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String N = in.next();
        nAsInt = Integer.valueOf(N);
        for (int i = 3; i < N.length() + 1; i++) {
            dfs(i, 0, 0);
        }
        System.out.println(count);
    }

    private static void dfs(int depth, int currentDepth, int value) {
        if (depth == currentDepth) {
            if (value <= nAsInt && String.valueOf(value).contains("3")
                    && String.valueOf(value).contains("5")
                    && String.valueOf(value).contains("7"))
            {
                count++;
            }
            return;
        }
        int nextValue = value + (int)Math.pow(10, currentDepth) * 7;
        dfs(depth, currentDepth + 1, nextValue);

        nextValue = value + (int)Math.pow(10, currentDepth) * 5;
        dfs(depth, currentDepth + 1, nextValue);

        nextValue = value + (int)Math.pow(10, currentDepth) * 3;
        dfs(depth, currentDepth + 1, nextValue);

    }

}