import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long x = scan.nextLong();
        long y = scan.nextLong();
        long tmp = y / x;
        for (int i = 0; i < 100; i++) {
            if(1L << i > tmp) {
                System.out.println(i);
                return;
            }
        }
    }
}