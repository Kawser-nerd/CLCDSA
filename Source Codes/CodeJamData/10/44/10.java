import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 *
 */
public class E {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    static class Circle {
        Coord c;
        double r;

        Circle(Coord c, double r) {
            this.c = c;
            this.r = r;
        }
    }



    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {

        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        int x, y;
        x = scanner.nextInt();
        y = scanner.nextInt();

        Coord c1 = new Coord(x, y);

        x = scanner.nextInt();
        y = scanner.nextInt();

        Coord c2 = new Coord(x, y);

        double result[] = new double[m];

        for (int i = 0; i < m; i++) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            Coord q = new Coord(x, y);

            double r1 = q.dist(c1);
            double r2 = q.dist(c2);

            Circle cc1 = new Circle(c1, r1);
            Circle cc2 = new Circle(c2, r2);

            result[i] = common(cc1, cc2);
        }

        wr.println("Case #" + caseNumber + ": " + printResult(result));
        System.out.println("Case #" + caseNumber + ": " + printResult(result));
        // ...
    }

    private static String printResult(double[] result) {
        String s = "";
        for (int i = 0; i < result.length; i++ ){
            if (i > 0) s += " ";
            s += result[i];
        }
        return s;
    }

    private static double common(Circle cc1, Circle cc2) {
        double c = cc1.c.dist(cc2.c);
        double r0 = cc1.r;
        double r1 = cc2.r;
        double cos_cba = (sqr(r1) + sqr(c) - sqr(r0))/(2*r1*c);

        double CBA = Math.acos(cos_cba);
        double CBD = 2*(CBA);

        double cos_CAB = (sqr(r0) + sqr(c) - sqr(r1))/(2*r0*c);

        double CAB = Math.acos(cos_CAB);
        double CAD = 2 * CAB;

        double area = (0.5)*(CBD)*sqr(r1) - (0.5)*sqr(r1)*Math.sin(CBD)
                    + (0.5)*(CAD)*sqr(r0) - (0.5)*sqr(r0)*Math.sin(CAD);


        return area;




        
    }

    private static double sqr(double d) {
        return d * d;
    }


    static class Coord {
        int x;
        int y;

        Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Coord coord = (Coord) o;

            if (x != coord.x) return false;
            if (y != coord.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        public double dist(Coord c) {
            return Math.sqrt(sqr(c.x - x) + sqr(c.y - y));
        }

        private double sqr(double d) {
            return d * d;
        }
    }




}