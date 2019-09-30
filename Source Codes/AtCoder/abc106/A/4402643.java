import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next()) - 1;
        int b = Integer.parseInt(sc.next()) - 1;
        System.out.println(a * b);
    }
}