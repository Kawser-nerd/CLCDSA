import java.util.Scanner;

import static java.lang.Math.abs;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();

        x2 -= x1;
        x3 -= x1;
        y2 -= y1;
        y3 -= y1;

        System.out.println(MyMath.area_of_triangle(new Point(x2,y2), new Point(x3, y3)));
    }
}

class MyMath {

    static double crossProduct(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double area_of_triangle(Point a, Point b) {
        return abs(crossProduct(a, b)) / 2.0;
    }
}

class Point {
    double x;
    double y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}