import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 2 ; i <= 55555; i++) {
            if (isPrime(i) && i % 5 == 3) {
                list.add(i);
            }
        }

        for (int i = 0 ; i < n ; i++) {
            System.out.print(list.get(i));
            System.out.print(" ");
        }
        System.out.println();
    }

    static boolean isPrime(int i) {
        for (int j = 2 ; j < Math.sqrt(i) ; j++) {
            if (i % j == 0) {
                return false;
            }
        }
        return true;
    }

}