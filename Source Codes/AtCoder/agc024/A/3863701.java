import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long k = sc.nextLong();
        if (k % 2 == 0) {
            System.out.println(a - b);
        } else {
            System.out.println(b - a);
        }
    }
}