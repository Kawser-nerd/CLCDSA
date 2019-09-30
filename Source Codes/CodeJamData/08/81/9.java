import java.io.*;
import java.util.StringTokenizer;
import java.util.Locale;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter("a.out");

        int N = Integer.parseInt(in.readLine());
        for (int i = 1; i <= N; i++) {
            double[] x1 = new double[3]; double[] y1 = new double[3];
            StringTokenizer tz = new StringTokenizer(in.readLine());
            for (int j = 0; j < 3; j++) {
                x1[j] = Integer.parseInt(tz.nextToken());
                y1[j] = Integer.parseInt(tz.nextToken());
            }
            double[] x2 = new double[3]; double[] y2 = new double[3];
            tz = new StringTokenizer(in.readLine());
            for (int j = 0; j < 3; j++) {
                x2[j] = Integer.parseInt(tz.nextToken());
                y2[j] = Integer.parseInt(tz.nextToken());
            }

            double dx1 = -x1[0], dy1 = -y1[0];
            for (int j = 0; j < 3; j++) {
                x1[j] += dx1; y1[j] += dy1;
            }
            double dx2 = -x2[0], dy2 = -y2[0];
            for (int j = 0; j < 3; j++) {
                x2[j] += dx2; y2[j] += dy2;
            }

            double scale = Math.hypot(x2[1], y2[1]) / Math.hypot(x1[1], y1[1]);
            for (int j = 0; j < 3; j++) {
                x2[j] /= scale; y2[j] /= scale;
            }
            double dd = x1[1]*x1[1]+y1[1]*y1[1];
            double sa = (x1[1]*y2[1]-x2[1]*y1[1])/dd;
            double ca = (x1[1]*x2[1]+y1[1]*y2[1])/dd;
            double a = ca*scale, b = -sa*scale, c = sa*scale, d = ca*scale;

            double dx = a*dx1+b*dy1 - dx2, dy = c*dx1+d*dy1-dy2;
            double de = (a-1)*(d-1)-c*b;
            double dex = -dx*(d-1)+dy*b;
            double dey = -(a-1)*dy+c*dx;
            double rx = dex /de, ry = dey/de;

            out.printf(Locale.US, "Case #%d: %.6f %.6f", i, rx, ry);
            out.println();
        }

        in.close();
        out.close();
    }
}