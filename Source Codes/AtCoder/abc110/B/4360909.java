import java.util.*;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();

        List<Integer> all_x = new ArrayList<>();
        all_x.add(x);
        for (int i = 0; i < n; i++) {
            all_x.add(sc.nextInt());
        }
        Collections.sort(all_x);

        List<Integer> all_y = new ArrayList<>();
        all_y.add(y);
        for (int i = 0; i < m; i++) {
            all_y.add(sc.nextInt());
        }
        Collections.sort(all_y);

        if (all_x.get(n) < all_y.get(0)) {
            System.out.println("No War");
        } else {
            System.out.println("War");
        }
    }

}