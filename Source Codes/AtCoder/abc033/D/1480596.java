import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

    private Map<String, Double> memo = new HashMap<>();

    private static class Point{
        long x;
        long y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Point> list = new ArrayList<>();
        for (int i = 0; i < n ; ++i) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            list.add(new Point(x, y));
        }
        long acuteAngle = 0; //??
        long rightAngle = 0; //??
        long obtuseAngle = 0; //??
        for (int i = 0; i < n; ++i) {
            int ct = 0;
            //
            double[] atan2 = new double[n + n - 2];
            //????
            Point p1 = list.get(i);
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    Point p2 = list.get(j);
                    //??????????
                    atan2[ct] = Math.atan2(p2.y - p1.y, p2.x - p1.x);
                    if (atan2[ct] < 0) {
                    	//?????????
                        atan2[ct] += Math.PI * 2;
                    }
                    ct++;
                }
            }
            for (int j = 0; j < n - 1; ++j) {
                atan2[ct++] = atan2[j] + Math.PI * 2;
            }
            Arrays.sort(atan2);
            for (int j = 0; j < n - 1; j++) {
                int tmp1 = 0;
                for (int k = 0; k < ct && atan2[tmp1] < atan2[j] + Math.PI / 2 - 1e-9; ++k) {
                    ++tmp1;
                }
                int tmp2 = tmp1;
                for (int k = tmp1; k < ct && atan2[tmp2] < atan2[j] + Math.PI / 2 + 1e-9; ++k) {
                    ++tmp2;
                }
                int tmp3 = tmp2;
                for (int k = tmp2; k < ct && atan2[tmp3] < atan2[j] + Math.PI - 1e-9; ++k) {
                    ++tmp3;
                }
                rightAngle += tmp2 - tmp1;
                obtuseAngle += tmp3 - tmp2;
            }
        }
        acuteAngle = (long)n * (n - 1) * (n- 2) / 6 - rightAngle - obtuseAngle;

        System.out.printf("%d %d %d%n", acuteAngle, rightAngle, obtuseAngle);
    }
}