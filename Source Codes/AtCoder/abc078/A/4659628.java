import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String x = sc.next();
        String y = sc.next();

        byte[] x_byte = x.getBytes();
        byte[] y_byte = y.getBytes();

        if (x_byte[0] > y_byte[0]) {
            System.out.println(">");
        } else if (x_byte[0] < y_byte[0]) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }

    }
}