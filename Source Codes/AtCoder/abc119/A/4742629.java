import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        String s = sc.next();
        String date[] = s.split("/");
        if (Integer.valueOf(date[1]) > 4) {
            System.out.println("TBD");
        } else {
            System.out.println("Heisei");
        }
    }
}