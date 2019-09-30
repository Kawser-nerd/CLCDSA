import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        if(a <= 0 && b >= 0) {
            System.out.println("Zero");
        } else if(a > 0) {
            System.out.println("Positive");
        } else if(b < 0) {
            if((b - a) % 2 == 1) {
                System.out.println("Positive");
            } else {
                System.out.println("Negative");
            }
        } else {
            if(a % 2 == 1) {
                System.out.println("Negative");
            } else {
                System.out.println("Positive");
            }
        }
    }
}