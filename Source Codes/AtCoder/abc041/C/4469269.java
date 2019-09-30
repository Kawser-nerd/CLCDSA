import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeMap<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) map.put(sc.nextInt(), i+1);
        map.forEach((x, y) -> System.out.println(y));
    }
}