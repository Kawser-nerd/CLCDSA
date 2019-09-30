//JTS used http://tsusiatsoftware.net/jts/
package round2;

import com.vividsolutions.jts.geom.*;
import com.vividsolutions.jtsexample.geom.ExtendedCoordinateSequence;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
    private static final int N = 100000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        Coordinate[] p = new Coordinate[n];
        Coordinate[] q = new Coordinate[m];
        for (int i = 0; i < n; i++) {
            p[i] = new Coordinate(in.nextDouble(), in.nextDouble());
        }
        for (int i = 0; i < m; i++) {
            q[i] = new Coordinate(in.nextDouble(), in.nextDouble());
        }

        DefaultCoordinateSequenceFactory csf = DefaultCoordinateSequenceFactory.instance();
        GeometryFactory gf = new GeometryFactory(new PrecisionModel(1000000000));

        String result = "";
        double aaa = (2 * Math.PI / N);
        double zzz = Math.sqrt(aaa / Math.sin(aaa));

        for (int i = 0; i < m; i++) {
            Polygon[] circles = new Polygon[n];
            for (int j = 0; j < n; j++) {
                double r = p[j].distance(q[i]);
                r = r * zzz; 
                Coordinate[] points = new Coordinate[N + 1];
                for (int k = 0; k < N; k++) {
                    double an = 2 * Math.PI * k / N;
                    points[k] = new Coordinate(p[j].x + r * Math.cos(an), p[j].y + r * Math.sin(an));
                }
                points[N] = points[0];
                //System.out.println(Arrays.toString(points));
                circles[j] = new Polygon(new LinearRing(
                        new ExtendedCoordinateSequence(points),
                        gf
                ), new LinearRing[0], gf);
            }
            Geometry res = circles[0];
            for (int j = 1; j < n; j++) {
                res = res.intersection(circles[j]);
            }
            result = result + res.getArea() + " ";
        }

        return result;
    }
}