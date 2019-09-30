import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 * @(#)CenterofMass.java, 2009-9-13. 
 * 
 * Copyright 2009 Yodao, Inc. All rights reserved.
 * YODAO PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/**
 *
 * @author Administrator
 *
 */
public class CenterofMass {
    private static final String INPUT = "input.txt";

    private static final String OUTPUT = "output.txt";
    
    private static int readInt(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        return Integer.parseInt(line);
    }
    
    private static int[] readInts(BufferedReader reader) throws Exception {
        String[] tokens = reader.readLine().split(" ");
        int[] res = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            res[i] = Integer.parseInt(tokens[i]);
        }
        return res;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(
                new FileInputStream(INPUT), "utf-8"));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream(OUTPUT), "utf-8"));
        int cn = readInt(reader);
        for (int t = 0; t < cn; t++) {
            int n = readInt(reader);
            double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++) {
                int[] a = readInts(reader);
                a1 += a[0];
                b1 += a[1];
                c1 += a[2];
                a2 += a[3];
                b2 += a[4];
                c2 += a[5];
            }
            a1 = a1 / n;
            a2 = a2 / n;
            b1 = b1 / n;
            b2 = b2 / n;
            c1 = c1 / n;
            c2 = c2 / n;
            double gama = a1 * a1 + b1 * b1 + c1 * c1;
            double beta = 2 * a1 * a2 + 2 * b1 * b2 + 2 * c1 * c2;
            double alpha =  a2 * a2 + b2 * b2 + c2 * c2;
            double time = -1;
            double val = -1;
            if (alpha > 0) {
                time = - beta / 2 / alpha;
                if (time < 0) {
                    time = 0;
                }
            } else {
                if (beta > 0) {
                    time = 0;
                } else if (beta < 0) {
                    time = - gama / beta;
                } else {
                    time = 0;
                }
            }
            double tm = alpha * time * time + beta * time + gama;
            if (Math.abs(tm) < 1e-8) {
                tm = 0;
            }
            val = Math.sqrt(tm);
            if (tm < 0)
            System.out.println(val + " " + tm);
            writer.write("Case #" + (t + 1) + ": " + val + " " + time + "\n");

            
            
        }
        reader.close();
        writer.close();
    }
}
