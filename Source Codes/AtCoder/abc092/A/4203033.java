import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, d;
        a = Integer.parseInt(sc.next());
        b = Integer.parseInt(sc.next());
        c = Integer.parseInt(sc.next());
        d = Integer.parseInt(sc.next());

        int min_1 = Math.min(a, b);
        int min_2 = Math.min(c, d);

        System.out.println(min_1 + min_2);

        sc.close();
    }
}