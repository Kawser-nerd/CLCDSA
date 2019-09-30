import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;

/**
 *
 */
public class C {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner("c:/projekty/gcj/input.txt");

            FileOutputStream out = new FileOutputStream("c:/projekty/gcj/output.txt");

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

        int m, n;
        n = sc.nextInt();
        m = sc.nextInt();

        int room[][] = new int[m][n];
        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.') {
                    room[j][i] = 1;
                } else {
                    room[j][i] = 0;
                }
            }
        }

        int []state = new int[1 << n];

        for (int i = 0; i < m; i++) {
            // for each column
            int broken = 0;
            for (int j = 0; j < n; j++) {
                if (room[i][j] == 0) {
                    broken |= (1 << j);
                }
            }
            int []newState = new int[1 << n];
            for (int j = 0; j < (1 << n); j++) {
                if ((j & broken) == 0) {
                    int s = getState(j);
                    int bits = getBits(j);
                    for (int k = 0; k < (1<<n); k++) {
                        if ((k & s) == 0) {
                            if (newState[s] < bits + state[k]) {
                                newState[s] = bits + state[k];
                            }
                        }
                    }
                }
            }
            state = newState;
        }

        int result = 0;
        for (int i = 0; i < (1<<n); i++) {
            if (state[i] > result) {
                result = state[i];
            }
        }

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
    }

    private static int getState(int j) {
        int result = j;
        for (int i = 1; i < 15; i++) {
            if ((j & (1<<i)) != 0) {
                result |= (1 << (i-1));
            }
        }
        return result;
    }

    private static int getBits(int j) {
        int bits = 0;
        while (j > 0) {
            if ((j & 1) == 1) {
                bits++;
            }
            j >>= 1;
        }
        return bits;
    }


}
