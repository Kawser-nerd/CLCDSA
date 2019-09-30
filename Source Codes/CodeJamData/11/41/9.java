import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int X = in.nextInt();
        int S = in.nextInt();
        int R = in.nextInt();
        int T = in.nextInt();
        int N = in.nextInt();
        int[] B = new int[N];
        int[] E = new int[N];
        int[] W = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = in.nextInt();
            E[i] = in.nextInt();
            W[i] = in.nextInt();
        }

        int[] l = new int[N];
        List<Line> lines = new ArrayList<Line>();
        int s = X;
        for (int i = 0; i < N; i++) {
            l[i] = E[i] - B[i];
            lines.add(new Line(l[i], W[i]));
            s -= (l[i]);
        }
        lines.add(new Line(s, 0));
        Collections.sort(lines);

        double runTimeLeft = T;
        double res = 0;
        for (Line line : lines) {
            double timeIfRun = 1.0 * line.length / (line.speed + R);
            if (timeIfRun <= runTimeLeft) {
                res += timeIfRun;
                runTimeLeft -= timeIfRun;
            } else {
                double distanceLeft = line.length - runTimeLeft * (line.speed + R);
                double time = runTimeLeft + 1.0 * distanceLeft / (line.speed + S);
                res += time;
                runTimeLeft = 0;
            }
        }

        return "" + res;
    }

    class Line implements Comparable<Line> {
        int length;
        int speed;

        Line(int length, int speed) {
            this.length = length;
            this.speed = speed;
        }

        public int compareTo(Line line) {
            return speed - line.speed;
        }
    }
}