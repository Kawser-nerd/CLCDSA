package codejam.y2012.r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

/**
 * @author Ilya Lantuh
 */
public class Task2 {

    static Scanner input;
    static BufferedWriter output;

    static class Circle implements Comparable<Circle> {

        double x;
        double y;
        double rad;
        int student;

        boolean intersect(Circle other) {
            double deltax = Math.abs(x - other.x);
            double deltay = Math.abs(y - other.y);
            double distance = Math.sqrt(deltax*deltax + deltay*deltay);
            return distance < (rad + other.rad);
        }

        public int compareTo(Circle o) {
            return student - o.student;
        }
    }

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int N = input.nextInt();
        int W = input.nextInt();
        int L = input.nextInt();
        int[] r = new int[N];
        for (int i = 0; i < N; i++) {
            r[i] = input.nextInt();
        }
        int c = 0;
        List<Circle> circles = new LinkedList<Circle>();
        i:
        for (int i = 0; i < W;) {
            j:
            for (int j = 0; j < L;) {
                Circle circle = new Circle();
                circle.x = i;
                circle.y = j;
                circle.rad = r[c];
                circle.student = c;
                for (Circle otherCircle : circles) {
                    if (circle.intersect(otherCircle)) {
                        int delta = (int) otherCircle.rad/4;
                        if (delta == 0) delta = 1;
                        if (j + delta < L) {
                            j += delta;
                            continue j;
                        } else if (i + delta < W) {
                            i += delta;
                            continue i;
                        } else {
                            throw new RuntimeException();
                        }
                    }
                }
                circles.add(circle);
                c++;
                if (c >= N) break i;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (Circle circle : circles) {
            sb.append(circle.x + " " + circle.y + " ");
        }

        return sb.toString();
    }

}
