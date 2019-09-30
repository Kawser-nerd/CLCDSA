import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();

            x -= z;

            System.out.println(x / (y + z));
        }
    }
}