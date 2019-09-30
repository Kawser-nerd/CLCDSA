import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = Integer.parseInt(sc.next());
        if (i % 2 == 0) {
            System.out.println((i / 2) * (i / 2));
        } else {
            System.out.println((i / 2) * (i / 2 + 1));
        }
    }
}