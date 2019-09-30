import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        List<Integer> xList = new ArrayList<>();
        List<Integer> yList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            xList.add(sc.nextInt());
        }
        for (int i = 0; i < m; i++) {
            yList.add(sc.nextInt());
        }

        Collections.sort(xList);
        Collections.sort(yList);
        for (int i = xList.get(n - 1) + 1; i <= yList.get(0); i++) {
            if (i > x && i <= y) {
                System.out.println("No War");
                return;
            }
        }
        System.out.println("War");
    }

}