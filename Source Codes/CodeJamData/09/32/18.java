package year2009.round1B.b;

import java.io.*;
import java.util.Scanner;

public class ProblemB implements Runnable {
    public static final String FILE_PREFIX = "B";


    public void run() {

        try {
            Scanner in = new Scanner(new BufferedReader(new FileReader(getInputFile())));
            PrintWriter out = new PrintWriter("output-"  + FILE_PREFIX + ".txt");
            int COUNT = in.nextInt();

            for (int pass = 0; pass < COUNT; pass ++) {
                int N = in.nextInt();
                double x =0, y=0, z = 0, dx = 0, dy = 0, dz = 0;
                for (int i = 0; i < N; i++) {
                    int swx = in.nextInt();
                    int swy = in.nextInt();
                    int swz = in.nextInt();
                    int swdx = in.nextInt();
                    int swdy = in.nextInt();
                    int swdz = in.nextInt();
                    x += swx;
                    y += swy;
                    z += swz;
                    dx += swdx;
                    dy += swdy;
                    dz += swdz;
                }
                x /= N;
                y /= N;
                z /= N;
                dx /= N;
                dy /= N;
                dz /= N;


                double t = 0;
                double d = Math.sqrt(x*x + y*y + z*z);

                double tleft = 0;
                double tright = 1e10;
                double v1 = 0;
                double v2 = 100;
                if (Math.abs(dx*dx + dy*dy + dz*dz) > 1e-8)  {
                    do {
                        double tr = (tright - tleft) / 3;
                        v1 = distAt(x,y,z,dx,dy,dz,tleft + tr);
                        v2 = distAt(x,y,z,dx,dy,dz,tleft + tr + tr);
                        if (v1 < v2) {
                            tright = tright - tr;
                        } else {
                            tleft = tleft + tr;
                        }

                    } while (Math.abs(tleft - tright) >= 1e-8 || Math.abs(v1 - v2) >= 1e-7 );

                    t = (tleft + tright) / 2;
                    d = distAt(x,y,z,dx,dy,dz,t);
                }
                out.printf("Case #%d: ", pass + 1);
//                System.err.println(dx + " " + dy + " " + dz);
                System.err.printf("%.8f %.8f %n", d, t);
                out.printf("%.6f %.6f", d, t);

                out.println();
            }




            out.close();
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    private double distAt(double x, double y, double z, double dx, double dy, double dz, double t) {
        return Math.sqrt(
                (x + dx * t)* (x + dx * t) +
                (y + dy * t)* (y + dy * t) +
                (z + dz * t)* (z + dz * t)
        );
    }

    public static void main(String[] args) {
        new Thread(new ProblemB()).start();
    }

    public File getInputFile() {
        File result = null;
        File temp = new File("input" + FILE_PREFIX + ".txt");
        if (temp.exists())  {
            result = temp;
        }
        temp = new File(FILE_PREFIX + "-small-attempt.in");
        if (temp.exists())  {
            result = temp;
        }
        int index = 0;
        temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        while (temp.exists())  {
            result = temp;
            index++;
            temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        }
        temp = new File(FILE_PREFIX + "-large.in");
        if (temp.exists())  {
            result = temp;
        }
        System.out.println("Using " + result);
        return result;
    }
}