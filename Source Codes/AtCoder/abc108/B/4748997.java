import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1 = Integer.parseInt(sc.next());
        int y1 = Integer.parseInt(sc.next());
        int x2 = Integer.parseInt(sc.next());
        int y2 = Integer.parseInt(sc.next());

        int vx = x2 - x1;
        int vy = y2 - y1;

        int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
        x3 = x2 - vy;
        y3 = y2 + vx;
        x4 = x1 - vy;
        y4 = y1 + vx;

        System.out.printf("%d %d %d %d\n", x3, y3, x4, y4); 
    }
}