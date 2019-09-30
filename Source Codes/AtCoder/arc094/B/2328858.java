import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Main main = new Main();
        // for (int i = 1; i < 30; i++) {
        // for (int j = 1; j < 30; j++) {
        // int ans = main.solveEachB(i, j);
        // int debugAns = solveDebug(i, j);
        // if (ans != debugAns) {
        // System.out.printf("%s:%s:%s:%s\n", i, j, ans, debugAns);
        // }
        // }
        // }
        new Main().solveB();
    }

    private static int solveDebug(int x, int y) {
        int you = x * y;
        int count = 0;
        boolean[] secondUsableCounts = new boolean[you];

        for (int i = 1; i < you; i++) {
            if (i == x) continue;
            for (int j = you; j >= 1; j--) {
                if (j == y) continue;
                if (i * j < you && !secondUsableCounts[j]) {
                    count++;
                    secondUsableCounts[j] = true;
                    break;
                }
            }
        }

        return count;
    }

    private void solveB() {

        try (Scanner sc = new Scanner(System.in);) {
            int q = sc.nextInt();
            for (int i = 0; i < q; i++) {
                long x = sc.nextLong();
                long y = sc.nextLong();
                long result = solveEachB(x, y);
                System.out.println(result);
            }

        }

        // System.out.println(Math.pow(sqrt, 2));
    }

    private long solveEachB(long x, long y) {
        long sum = x * y;

        long sqrt = (int) Math.sqrt(sum);
        if (Math.pow(sqrt, 2) == sum) {
            sqrt--;
        }
        long result = sqrt * 2;
        if (sqrt * (sqrt + 1) >= sum) {
            result--;
        }
        if (sqrt >= x) result--;
        if (sqrt >= y && x != y) result--;

        return result;
    }

    private void solveA() {

        List<Integer> list = new ArrayList<>();
        try (Scanner sc = new Scanner(System.in);) {
            list.add(sc.nextInt());
            list.add(sc.nextInt());
            list.add(sc.nextInt());
        }
        Collections.sort(list);
        int min = list.get(0);
        int middle = list.get(1);
        int max = list.get(2);
        int count = 0;

        while (min != middle || middle != max) {
            for (int i = 0; i < 2; i++) {
                min++;
                if (min > middle) {
                    int tmp = middle;
                    middle = min;
                    min = tmp;
                }
                if (min > max) {
                    int tmp = max;
                    max = min;
                    min = tmp;
                }
            }
            count++;
        }

        System.out.println(count);
    }
}