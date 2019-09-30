import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();

        int sum = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int price = sc.nextInt();
            sum += price;
            max = Math.max(max, price);
        }
        System.out.println(sum - (max/2));
    }
}