import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        int x3 = 0;
        int y3 = 0;
        int x4 = 0;
        int y4 = 0;

        if (x1 >= x2) {
            y3 = y2 - Math.abs(x1 - x2);
            y4 = y1 - Math.abs(x1 - x2);
        } else {
            y3 = y2 + Math.abs(x1 - x2);
            y4 = y1 + Math.abs(x1 - x2);
        }
        if (y1 >= y2) {
            x3 = x2 + Math.abs(y1 - y2);
            x4 = x1 + Math.abs(y1 - y2);
        } else {
            x3 = x2 - Math.abs(y1 - y2);
            x4 = x1 - Math.abs(y1 - y2);
        }
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }

}