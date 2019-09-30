package zhang00000;

import com.sun.tools.javac.jvm.Code;
import org.apache.commons.math3.complex.Complex;
import org.apache.commons.math3.util.Pair;

import java.io.*;
import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.*;


public class App {
    final int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
    final int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
    final int diK[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    final int djK[] = {-1, 1, 2, 2, 1, -1, -2, -2};

    public static void main(String[] args) {
        if (args.length == 1) {
            String filename = "src/main/java/zhang00000/" + args[0] + ".in";
            if (!filename.isEmpty()) try {
                System.setIn(new FileInputStream(filename));
            } catch (FileNotFoundException e) {
                System.out.println(e.getMessage());
                System.exit(1);
            }
        }

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = Integer.valueOf(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int number = 1; number <= t; number++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] matrix = new int[n][n];
            int[] a1 = new int[n];
            int[] a2 = new int[n];
            int[] b1 = new int[2 * n - 1];
            int[] b2 = new int[2 * n - 1];
            char[] cs = new char[]{'.', 'x', '+', 'o'};
            Set<Pair<Integer, Integer>> set = new HashSet<>();
            in.nextLine();
            for (int k = 0; k < m; k++) {
                String[] ss = in.nextLine().split(" ");
                char ch = ss[0].charAt(0);
                int i = Integer.valueOf(ss[1]) - 1;
                int j = Integer.valueOf(ss[2]) - 1;
                if (ch == 'x' || ch == 'o') {
                    a1[i] = 1;
                    a2[j] = 1;
                    matrix[i][j] += 1;
                }
                if (ch == '+' || ch == 'o') {
                    b1[i + j] = 1;
                    b2[i - j + n - 1] = 1;
                    matrix[i][j] += 2;
                }
            }
            int i = 0;
            int j = 0;
            while (i < n && j < n) {
                while (i < n && a1[i] == 1) i++;
                while (j < n && a2[j] == 1) j++;
                if (i < n && j < n) {
                    set.add(new Pair<>(i, j));
                    matrix[i++][j++] += 1;
                }
            }
            List<Integer> mapi = new ArrayList<>();
            List<Integer> mapj = new ArrayList<>();
            for (int k = 0; k < n; k++) {
                mapi.add(k);
                if (k != n - 1) mapi.add(2 * n - 2 - k);
                mapj.add(n - 1 - k);
                if (k != 0) mapj.add(n - 1 + k);
            }
            for (i = 0; i < 2 * n - 1; i++) {
                if(b1[mapi.get(i)] == 1) continue;
                for (j = 0; j < 2 * n - 1; j++) {
                    if((mapj.get(j) + mapi.get(i) - n + 1) % 2 != 0) continue;
                    if(b2[mapj.get(j)] == 1) continue;
                    int i1 = (mapi.get(i) + mapj.get(j) - n + 1) / 2;
                    int j1 = (mapi.get(i) - mapj.get(j) + n - 1) / 2;
                    if(i1<0 || i1>=n || j1<0 ||  j1>=n) continue;
                    b1[mapi.get(i)] = 1;
                    b2[mapj.get(j)] = 1;
                    set.add(new Pair<>(i1, j1));
                    matrix[i1][j1]+=2;
                    break;
                }
            }
            int sum2 = Arrays.stream(b1).sum() + n;
            System.out.println("Case #" + number + ": "  + sum2 + " " + set.size());

            for (Pair<Integer, Integer> p: set) {
                System.out.println(cs[matrix[p.getFirst()][p.getValue()]] + " " + (p.getFirst()+1) + " " + (p.getValue()+1));
            }


        }
    }

}