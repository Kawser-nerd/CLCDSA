import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        if (n % k == 0) {
            System.out.println(0);
        } else {
            System.out.println(1);
        }
    }
}