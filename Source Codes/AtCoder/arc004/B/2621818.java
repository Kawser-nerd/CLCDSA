import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int sum = 0, max = 0;
        for(int i = 0; i < n; i++) {
            int d = in.nextInt();
            sum += d;
            max = Math.max(d, max);
        }
        System.out.println(sum);
        System.out.println(Math.max(0, 2 * max - sum));
    }
}