package com.mavtushenko.Gcj1C;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class TaskC {
    public static void main(String[] args) {
        String fileName = "C-large.in";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName + ".out"))) {
                int tests = Integer.valueOf(br.readLine());
                for (int test = 1; test <= tests; ++test) {
                    Scanner scanner = new Scanner(br.readLine());
                    int j = scanner.nextInt();
                    int p = scanner.nextInt();
                    int s = scanner.nextInt();
                    int k = scanner.nextInt();
                    int jp[][] = new int[j][p];
                    for (int[] row : jp)
                        Arrays.fill(row, k);
                    int js[][] = new int[j][s];
                    for (int[] row : js)
                        Arrays.fill(row, k);
                    int ps[][] = new int[p][s];
                    for (int[] row : ps)
                        Arrays.fill(row, k);

                    boolean check[][][] = new boolean[j][p][s];
                    for (boolean[][] matr : check)
                        for (boolean[] row : matr)
                            Arrays.fill(row, false);
                    int curS = 0;
                    int curK = 1;
                    int res = 0;
                    int step = Math.min(s, k);
                    StringBuffer sb = new StringBuffer();
                    for (int jj = 0; jj < j; ++jj) {
                        int curSS = curS;
                        int curKJ = 1;
                        for (int pp = 0; pp < p; ++pp) {
                            int kk = k;
                            int ss = curSS;
                            int curKK = curK;
                            while (kk != 0) {
                                ++res;
                                sb.append("" + (jj + 1) + " " + (pp + 1) + " " + (ss + 1) + "\n");
                                jp[jj][pp]--;
                                js[jj][ss]--;
                                ps[pp][ss]--;
                                if (jp[jj][pp] < 0 || js[jj][ss] < 0 || ps[pp][ss] < 0)
                                    break;
                                if (check[jj][pp][ss])
                                    break;
                                check[jj][pp][ss] = true;
                                --kk;
                                ++ss;
                                if (ss == s)
                                    ss = 0;
                                if (ss == curSS) {
                                    if (curKK < k) {
                                        ++curKK;
                                    } else
                                        break;
                                }
                                if (curSS == ss)
                                    break;
                            }
                            curSS += step;
                            if (curSS >= s) {
                                curSS -= s;
                            }
                        }
                        curS += step;
                        if (curS >= s) {
                            if (curK < k) {
                                curS -= s;
                                curK++;
                            } else {
                                break;
                            }
                        }
                    }
                    for (int i1 = 0; i1 < j; i1++) {
                        for (int i2 = 0; i2 < p; ++i2) {
                            for (int i3 = 0; i3 < s; ++i3) {
                                if (!check[i1][i2][i3]) {
                                    if (jp[i1][i2] > 0 && js[i1][i3] > 0 && ps[i2][i3] > 0)
                                        break;
                                }
                            }
                        }
                    }
                    bw.write("Case #" + test + ": " + res + "\n");
                    bw.write(sb.toString());
                }
                bw.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
