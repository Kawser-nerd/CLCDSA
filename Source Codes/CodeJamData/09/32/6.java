package rueustas;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;

public class ProbB {
    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader(new File("b.in"));
        FileWriter writer = new FileWriter(new File("b.out"));
        BufferedReader in = new BufferedReader(reader);
        String tStr = in.readLine();
        int T = Integer.parseInt(tStr);
        for (int t = 1; t <= T; t++) {
            String nStr = in.readLine();
            int N = Integer.parseInt(nStr);
            long sx = 0;
            long sy = 0;
            long sz = 0;
            long svx = 0;
            long svy = 0;
            long svz = 0;
            for (int n = 0; n < N; n++) {
                String[] co = in.readLine().trim().split(" ");
                long x = Long.parseLong(co[0]);
                long y = Long.parseLong(co[1]);
                long z = Long.parseLong(co[2]);
                long vx = Long.parseLong(co[3]);
                long vy = Long.parseLong(co[4]);
                long vz = Long.parseLong(co[5]);
                sx += x;
                sy += y;
                sz += z;
                svx += vx;
                svy += vy;
                svz += vz;
            }
            long b = (sx * svx) + (sy * svy) + (sz * svz);
            long a = (svx * svx) + (svy * svy) + (svz * svz);
            double ti = 0.0;
            if (a != 0) {
                ti = (-b + 0.0) / (a + 0.0);
            }
            if (ti < 0.0) {
                ti = 0.0;
            }
            double l2 = (sx + ti * svx) * (sx + ti * svx) + (sz + ti * svz) * (sz + ti * svz) + (sy + ti * svy) * (sy + ti * svy);
            double l = Math.sqrt(l2) / N;

            writer.append("Case #" + String.valueOf(t) + ": " + String.format(Locale.ENGLISH, "%.8f %.8f", l, ti) + "\r\n");
        }
        reader.close();
        writer.close();
    }
}