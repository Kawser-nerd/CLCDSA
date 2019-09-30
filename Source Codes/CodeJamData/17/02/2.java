package qualifier;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class BTidyNumbers {
    public static void main (String[] args) {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int tests = sc.nextInt();
            for (int t = 1; t <= tests; t++) {
                //calculate result
                int[] digits = sc.next().chars().map(i -> i - '0').toArray();
                for (int x = 0; x < digits.length - 1; x++) {
                    if (digits[x] > digits[x + 1]) {
                        digits[x]--;
                        for (int y = x + 1; y < digits.length; y++) digits[y] = 9;
                        while(digits[x] < 0 || (x > 0 && digits[x] < digits[x - 1])) {
                            digits[x] = 9;
                            digits[x - 1]--;
                            x--;
                        }
                        break;
                    }
                }
                //print result
                int start = 0;
                while(digits[start] == 0) start++;
                StringBuilder sb = new StringBuilder();
                for (int x = start; x < digits.length; x++) sb.append((char)(digits[x] + '0'));
                System.out.printf("Case #%d: %s%n", t, sb.toString());
            }
        }
    }
}
