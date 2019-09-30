import java.util.Scanner;

public class Main {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args) {
        final int A = s.nextInt();
        final int B = s.nextInt();
        System.out.println(B % A == 0 ? A + B : B - A);
    }
}