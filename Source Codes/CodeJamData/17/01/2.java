package qualifier;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class AOversizedPancakeFlipper {
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int tests = sc.nextInt();
            outer:
            for (int t = 1; t <= tests; t++) {
                char[] happyChars = sc.next().toCharArray();
                int spatWidth = sc.nextInt();
                
                boolean[] happy = new boolean[happyChars.length];
                for (int x = 0; x < happy.length; x++) happy[x] = happyChars[x] == '+';
                List<Integer> flipPoints = new LinkedList<Integer>();
                int flipCount = 0;
                boolean flipped = false;
                
                for (int x = 0; x <= happy.length - spatWidth; x++) {
                    if (!flipPoints.isEmpty() && flipPoints.get(0) == x) {
                        flipPoints.remove(0);
                        flipped = !flipped;
                    }
                    boolean current = happy[x] != flipped;
                    if (!current) {
                        flipped = !flipped;
                        flipCount++;
                        flipPoints.add(x + spatWidth);
                    }
                }
                
                for (int x = happy.length - spatWidth + 1; x < happy.length; x++) {
                    if (!flipPoints.isEmpty() && flipPoints.get(0) == x) {
                        flipPoints.remove(0);
                        flipped = !flipped;
                    }
                    if (happy[x] == flipped) {
                        System.out.printf("Case #%d: IMPOSSIBLE%n", t);
                        continue outer;
                    }
                }
                System.out.printf("Case #%d: %d%n", t, flipCount);
            }
        }
    }
}
