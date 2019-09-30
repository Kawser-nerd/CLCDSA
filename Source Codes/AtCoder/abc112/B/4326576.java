import java.util.*;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int time = sc.nextInt();
        List<Integer> c = new ArrayList<>();
        List<Integer> t = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            c.add(sc.nextInt());
            t.add(sc.nextInt());

        }
        for (int i = n - 1; i >= 0; i--) {
            if (t.get(i) > time) {
                c.remove(i);
                t.remove(i);
            }
        }
        if (c.size() > 0) {
            Collections.sort(c);
            System.out.println(c.get(0));
        } else {
            System.out.println("TLE");
        }
    }

}