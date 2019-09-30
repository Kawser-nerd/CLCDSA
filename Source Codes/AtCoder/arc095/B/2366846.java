import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // new Main().solveA();
        new Main().solveB();

        // List<Integer> list = new ArrayList<>();
        //
        // for (int i = 1; i < 10; i += 2) {
        // list.add(i);
        // }
        //
        // for (int j = 1; j <= 10; j++) {
        // System.out.printf("%s:%s\n", j, Collections.binarySearch(list, j));
        // }

        // int max = 0;
        // int eCount = 11;
        // int sum = 1;
        // int jindex = 1;
        // for (int i = 1; i <= eCount; i++) {
        // sum = sum * (eCount - i + 1);
        // jindex = jindex * (i);
        // System.out.printf("%s : %s, %s, %s \n", i, sum, jindex, sum / jindex);
        // if (max <= sum / jindex) {
        // max = sum / jindex;
        // System.out.println("max update");
        // }
        // }

    }

    private void solveB() {
        try (Scanner sc = new Scanner(new BufferedInputStream(System.in, 8096));) {
            List<Integer> list = new ArrayList<>();
            int N = sc.nextInt();
            for (int i = 0; i < N; i++) {
                list.add(sc.nextInt());
            }

            Collections.sort(list);
            int max = list.remove(list.size() - 1);
            if (list.size() == 1) {
                System.out.printf("%s %s\n", max, list.get(0));
                return;
            }

            int[] targets = new int[2];
            targets[0] = max / 2;
            if (max % 2 == 0) {
                targets[1] = targets[0];
            } else {
                targets[1] = targets[0] + 1;
            }

            int binarySearch = Collections.binarySearch(list, targets[0]);
            int binarySearch2 = Collections.binarySearch(list, targets[1]);

            if (binarySearch >= 0) {
                System.out.printf("%s %s\n", max, list.get(binarySearch));
                return;
            }
            if (binarySearch2 >= 0) {
                System.out.printf("%s %s\n", max, list.get(binarySearch2));
                return;
            }

            int a = list.get(Math.min(Math.abs(binarySearch + 1), list.size() - 1));
            int b = list.get(Math.abs(binarySearch + 2));
            int c = list.get(Math.min(Math.abs(binarySearch2 + 1), list.size() - 1));
            int d = list.get(Math.abs(binarySearch2 + 2));

            int nearA = Math.min(Math.abs(targets[0] - a), Math.abs(targets[1] - a));
            int nearB = Math.min(Math.abs(targets[0] - b), Math.abs(targets[1] - b));
            int nearC = Math.min(Math.abs(targets[0] - c), Math.abs(targets[1] - c));
            int nearD = Math.min(Math.abs(targets[0] - d), Math.abs(targets[1] - d));

            if (nearA <= nearB && nearA <= nearC && nearA <= nearC && nearA <= nearD) {
                System.out.printf("%s %s\n", max, a);
                return;
            }
            if (nearB <= nearC && nearB <= nearD) {
                System.out.printf("%s %s\n", max, b);
                return;
            }
            if (nearC <= nearD) {
                System.out.printf("%s %s\n", max, c);
                return;
            }
            System.out.printf("%s %s\n", max, d);
            return;
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