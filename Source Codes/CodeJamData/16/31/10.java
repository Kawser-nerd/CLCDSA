package com.mavtushenko.Gcj1C;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TaskA {
    public static void main(String[] args) {
        String fileName = "A-large.in";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileName + ".out"))) {
                int tests = Integer.valueOf(br.readLine());
                for (int test = 1; test <= tests; ++test) {
                    int n = new Scanner(br.readLine()).nextInt();
                    Scanner scanner = new Scanner(br.readLine());
                    int s[] = new int[n];
                    for (int i = 0; i < n; ++i)
                        s[i] = scanner.nextInt();
                    bw.write("Case #" + test + ": ");
                    while (true) {
                        int max = 0;
                        for (int ss: s)
                            max = Math.max(max, ss);
                        if (max == 0)
                            break;
                        ArrayList<Integer> pos = new ArrayList<Integer>();
                        for (int i = 0; i < n; ++i) {
                            if (s[i] == max)
                                pos.add(i);
                        }
                        int ps = pos.size();
                        if (pos.size() % 2 == 1) {
                            ps--;
                            int cur = pos.get(pos.size() - 1);
                            s[cur]--;
                            bw.write("" + (char)('A' + cur) + " ");
                        }
                        for (int i = 0; i < ps; i += 2) {
                            int c1 = pos.get(i);
                            int c2 = pos.get(i + 1);
                            s[c1]--;
                            s[c2]--;
                            bw.write("" + (char)('A' + c1) + (char)('A' + c2) + " ");
                        }
                    }
                    bw.write("\n");
                }
                bw.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
