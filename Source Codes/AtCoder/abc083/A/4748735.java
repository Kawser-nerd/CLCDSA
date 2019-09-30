import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, d;
        a = Integer.parseInt(sc.next());
        b = Integer.parseInt(sc.next());
        c = Integer.parseInt(sc.next());
        d = Integer.parseInt(sc.next());
        int left = a + b;
        int right = c + d;
        if (left > right) {
            System.out.println("Left");
        } else if (left < right) {
            System.out.println("Right");
        } else {
            System.out.println("Balanced");
        }
        sc.close();
    }
}