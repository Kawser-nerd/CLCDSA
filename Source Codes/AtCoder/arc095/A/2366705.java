import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().solveA();
        // new Main().solveB();
    }

    private void solveB() {

        try (Scanner sc = new Scanner(System.in);) {

        }
    }

    private void solveA() {
        try (Scanner sc = new Scanner(new BufferedInputStream(System.in, 8096));) {
            List<Integer> list = new ArrayList<>();
            int N = sc.nextInt();
            for (int i = 0; i < N; i++) {
                list.add(sc.nextInt());
            }

            List<Integer> sortedList = new ArrayList<>(list);

            Collections.sort(sortedList);

            int median = sortedList.get(N / 2);
            int medianMinus = sortedList.get(N / 2 - 1);

            for (int i : list) {
                if (i >= median) {
                    System.out.println(medianMinus);
                } else {
                    System.out.println(median);
                }
            }
        }
    }

}