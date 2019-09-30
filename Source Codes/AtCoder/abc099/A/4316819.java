import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.nextInt() <= 999) {
            System.out.println("ABC");
            return;
        }
        System.out.println("ABD");
    }

}