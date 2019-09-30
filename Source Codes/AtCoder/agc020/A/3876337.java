import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        if ((b - a) % 2 == 1) {
            System.out.println("Borys");
        } else {
            System.out.println("Alice");
        }
    }
}