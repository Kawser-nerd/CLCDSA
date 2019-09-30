import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.Arrays;

/**
 *
 */
public class A {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner("c:/input.txt");

            FileOutputStream out = new FileOutputStream("c:/output.txt");

            int numberOfCases;
            numberOfCases = scanner.nextInt();

            PrintWriter wr = new PrintWriter(out);
            for (int i = 0; i < numberOfCases; i++) {
                doCase(i + 1, scanner, wr);
            }
            wr.close();
            out.close();

        } catch (IOException e) {
            System.out.println("Error: " + e);
        }
    }

    private static void doCase(int caseNumber, Scanner sc, PrintWriter wr) throws IOException {
        int P, K, L;
        P = sc.nextInt();
        K = sc.nextInt();
        L = sc.nextInt();
        int []freq = new int[L];

        for (int i = 0; i < L; i++) {
            freq[i] = sc.nextInt();
        }

        Arrays.sort(freq);

        long result = 0;
        int keyPress = 1;
        int keyCounter = 0;
        for (int i = L - 1; i >= 0; i--) {
            if (++keyCounter > K) {
                keyCounter = 1;
                keyPress++;
            }
            result += freq[i] * keyPress;
        }

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
    }


}
