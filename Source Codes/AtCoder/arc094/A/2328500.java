import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().solveA();
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