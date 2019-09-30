package com.company;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    static private void reDirect() {
        try {
            FileInputStream fileInputStream = new FileInputStream("A-large.in");
            //System.setIn(fileInputStream);
            scanner = new Scanner(fileInputStream);

            PrintStream ps = new PrintStream(new FileOutputStream("a-out-large.txt"));
            System.setOut(ps);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        reDirect();
        int T = scanner.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            int ans = run();
            System.out.println("Case #" + cas + ": " + (ans < 0 ? "IMPOSSIBLE" : ans));
        }
    }

    static private int run() {
        String s = scanner.next();
        int k = scanner.nextInt();
        char[] arr = s.toCharArray();
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '-') {
                if (i + k > arr.length) {
                    return -1;
                }
                count++;
                for (int j = i; j < i + k; j++) {
                    arr[j] = (arr[j] == '+' ? '-' : '+');
                }
            }
        }
        return count;
    }
}
