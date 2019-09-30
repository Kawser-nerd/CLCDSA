import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Double x1 = sc.nextDouble();
        Double y1 = sc.nextDouble();
        Double x2 = sc.nextDouble();
        Double y2 = sc.nextDouble();
        Double x3 = sc.nextDouble();
        Double y3 = sc.nextDouble();
        x3 -= x1;
        y3 -= y1;
        x2 -= x1;
        y2 -= y1;
        x1 -= x1;
        y1 -= y1;
        System.out.println(Math.abs((x3 * y2) - x2 * y3) / 2);
    }
}