import java.util.*;
import java.lang.Math;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        double x3 = x2 + ((x1-x2)*Math.cos(-Math.PI/2) - (y1-y2)*Math.sin(-Math.PI/2));
        double y3 = y2 + ((x1-x2)*Math.sin(-Math.PI/2) + (y1-y2)*Math.cos(-Math.PI/2));
        double x4 = x1 + ((x2-x1)*Math.cos(Math.PI/2) - (y2-y1)*Math.sin(Math.PI/2));
        double y4 = y1 + ((x2-x1)*Math.sin(Math.PI/2) + (y2-y1)*Math.cos(Math.PI/2));
        System.out.println((int)Math.rint(x3)+" "
                          +(int)Math.rint(y3)+" "
                          +(int)Math.rint(x4)+" "
                          +(int)Math.rint(y4));
        sc.close();
    }
}