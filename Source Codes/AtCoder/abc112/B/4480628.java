import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        List<Integer> cList = new ArrayList<>();
        List<Integer> tList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cList.add(sc.nextInt());
            tList.add(sc.nextInt());
        }
        Integer minCost = null;
        for (int i = 0; i < n; i++) {
            if (tList.get(i) > t) {
                continue;
            }
            int cost = cList.get(i);
            if (minCost == null || cost < minCost) {
                minCost = cost;
            }
        }
        if (minCost == null) {
            System.out.println("TLE");
            return;
        }
        System.out.println(minCost);
    }

}