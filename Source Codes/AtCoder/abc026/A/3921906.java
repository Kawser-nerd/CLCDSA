import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int max = 0;
        for (int x = 1; x < 100; x++) {
            for (int y = 1; y < 100; y++) {
                if (A == x + y) {
                    max = Math.max(x * y, max);
                }
            }
        }
        System.out.println(max);
    }
}