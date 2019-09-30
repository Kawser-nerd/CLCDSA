import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Arrays;

/**
 *
 */
public class C {
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

    public static class Counts {

        HashMap<Integer, Integer> indexes = new HashMap<Integer, Integer>();

        //int []counts;
        //int []counts1;
        //int []idx;
        int num;
        public int[][] sums;
        int bits;

        public Counts(int maxSize) {
            int cnt = 0;
            int s = maxSize;
            while (s > 0) {
                cnt++;
                s = s >> 1;
            }
            bits = cnt + 3;
            sums = new int[bits][];
            s = maxSize;
            for (int i = 0; i < bits; i++) {
                sums[i] = new int[s + 100];
                cnt++;
                s = s >> 1;
            }
        }
    }

    private static void doCase(int caseNumber, Scanner sc, PrintWriter wr) throws IOException {

        long n, m, X, Y, Z;
        n = sc.nextInt();
        m = sc.nextInt();
        X = sc.nextInt();
        Y = sc.nextInt();
        Z = sc.nextInt();

        int []lim = new int[(int)n];

        long []A = new long[(int)m];
        for (int i = 0; i < m; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            lim[i] = (int)A[(int)(i % m)];
            A[(int)(i % m)] = (X * A[(int)(i % m)] + Y * (i + 1)) % Z;
        }


        Counts counts = new Counts((int)n);
        int []lim1 = new int[(int)n];
        System.arraycopy(lim, 0, lim1, 0, (int)n);
        Arrays.sort(lim1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && lim1[i-1] == lim1[i]) continue;
            counts.indexes.put(lim1[i], cnt++);
        }



        for (int i = 0; i < n; i++) {
            int sum = (getSum(lim[i], counts) + 1) % 1000000007;
            setSum(lim[i], sum, counts);
        }

        int result = counts.sums[counts.bits - 1][0];
//        for (int i = 0; i < counts.num; i++) {
//            result = (result + counts.counts[i]) % 1000000007;
//        }
        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
    }

//    private static void setSum(int value, int sum, Counts counts) {
//        for (int i = 0; i < counts.num; i++) {
//            if (counts.idx[i] == value) {
//                counts.counts[i] = (counts.counts[i] + sum) % 1000000007;
//                return;
//            }
//        }
//
//        counts.idx[counts.num] = value;
//        counts.counts[counts.num] = sum;
//        counts.num++;
//    }

    private static int getSum(int value, Counts counts) {
        // get sum of values for all indexes less than value
        int idx = counts.indexes.get(value);
        //if (idx == 0) return counts.sums[0][0];
      //  if (idx == 0) return 0;
        int result = 0;
        int bit = 0;

        while (idx > 0) {
            if ((idx & 1) != 0) {
                result = (result + counts.sums[bit][idx - 1]) % 1000000007;
            }
            idx = idx >> 1;
            bit++;
        }

        return result;
    }

    private static void setSum(int value, int sum, Counts counts) {
        int idx = counts.indexes.get(value);
 //       idx++;
        //if (idx == 0) return 0;
        //int result = 0;
        int bit = 0;
        for (int i = 0; i < counts.bits; i++) {
//            if ((idx & 1) != 0) {
            counts.sums[i][idx] = (sum + counts.sums[i][idx]) % 1000000007;
            idx = idx >> 1;
        }


    }




}
