import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sx = sc.nextInt();
        int sy = sc.nextInt();
        int tx = sc.nextInt();
        int ty = sc.nextInt();

        int xd = tx - sx;
        int yd = ty - sy;

        for (int y = 0; y < yd; y++) {
            out.print("U");
        }

        for (int x = 0; x < xd; x++) {
            out.print("R");
        }

        for (int y = 0; y < yd; y++) {
            out.print("D");
        }

        for (int x = 0; x < xd; x++) {
            out.print("L");
        }

        out.print("L");
        for (int y = 0; y < yd + 1; y++) {
            out.print("U");
        }

        for (int x = 0; x < xd + 1; x++) {
            out.print("R");
        }
        out.print("D");

        out.print("R");
        for (int y = 0; y < yd + 1; y++) {
            out.print("D");
        }

        for (int x = 0; x < xd + 1; x++) {
            out.print("L");
        }
        out.print("U");

        out.println();
    }
}