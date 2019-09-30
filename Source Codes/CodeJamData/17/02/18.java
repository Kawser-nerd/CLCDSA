package com.company;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class ProbB {
    private Scanner scanner = new Scanner(System.in);

    public void main() {
        reDirect();
        int T = scanner.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            long ans = run();
            System.out.println("Case #" + cas + ": " + ans);
        }
    }

    private long run() {
        long input = scanner.nextLong();
        char[] arr = Long.valueOf(input).toString().toCharArray();
        int x = arr.length;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                x = i + 1;
                break;
            }
        }
        if (x == arr.length) {
            return input;
        }
        int y = x - 1;
        while (y > 0 && arr[y] == arr[y - 1]) y--;

        arr[y]--;
        for (int i = y + 1; i < arr.length; i++) {
            arr[i] = '9';
        }

        return Long.valueOf(new String(arr));
    }

    private void reDirect() {
        try {
            FileInputStream fileInputStream = new FileInputStream("B-large.in");
            //System.setIn(fileInputStream);
            scanner = new Scanner(fileInputStream);

            PrintStream ps = new PrintStream(new FileOutputStream("bout-large.txt"));
            System.setOut(ps);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
