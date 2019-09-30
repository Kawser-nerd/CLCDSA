import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int x = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        if (-a + b <= 0) {
            System.out.println("delicious");
        } else if (-a + b <= x) {
            System.out.println("safe");
        } else{
            System.out.println("dangerous");
        }
    }
}