import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String n = sc.next();

        if (n.contains("9")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}