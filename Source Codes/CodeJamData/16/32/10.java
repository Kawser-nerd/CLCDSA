package com.mavtushenko.Gcj1C;

import java.io.*;
import java.util.Scanner;

public class TaskB {
    public static void main(String[] args) {
        String fileName = "B-large.in";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName + ".out"))) {
                int tests = Integer.valueOf(br.readLine());
                for (int test = 1; test <= tests; ++test) {
                    Scanner scanner = new Scanner(br.readLine());
                    int b = scanner.nextInt();
                    long m = scanner.nextLong();
                    long initM = m;
                    bw.write("Case #" + test + ": ");
                    int tt[][] = new int[b][b];
                    long max = ((long) Math.pow(2, b - 2));
                    if (m > max) {
                        bw.write("IMPOSSIBLE\n");
                    } else {
                        bw.write("POSSIBLE\n");
                        StringBuffer res = new StringBuffer();
                        if (m == max) {
                            res.append("1");
                            tt[0][b - 1] = 1;
                            --m;
                        } else {
                            res.append("0");
                            tt[0][b - 1] = 0;
                        }

                        for (int i = 1; i < b; ++i) {
                            boolean set = (m & 1) != 0;
                            res.append(set ? "1" : "0");
                            tt[0][b - 1 - i] = set ? 1 : 0;
                            m = m >> 1;
                        }
                        bw.write(res.reverse().toString() + "\n");
                        for (int i = 2; i < b + 1; ++i) {
                            StringBuffer sb = new StringBuffer();

                            for (int j = 0; j < i; ++j) {
                                sb.append("0");
                                tt[i - 1][j] = 0;
                            }
                            for (int j = 0; j < b - i; ++j) {
                                sb.append("1");
                                tt[i - 1][j + i] = 1;
                            }
                            sb.append("\n");
                            bw.write(sb.toString());
                        }
                        long val[] = new long[b];
                        for (int i = 0; i < b; ++i)
                            val[i] = 0;
                        val[b - 1] = 1;
                        for (int i = 0; i < b; ++i) {
                            for (int j = b - i - 1; j >= 0; --j) {
                                if (tt[j][b - i - 1] == 1)
                                    val[j] += val[b - i - 1];
                            }
                        }
                        if (initM != val[0])
                            break;
                    }

                }
                bw.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}