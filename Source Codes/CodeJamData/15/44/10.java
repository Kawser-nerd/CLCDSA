import java.util.*;
import java.io.*;

public class D
{
    static long M = 1000000007;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int R = input.nextInt();
            int C = input.nextInt();

            long[] table = new long[R + 1];
            long[] table3s = new long[R + 1];
            long[] tableA3 = new long[R + 1];
            long[] table3sA3 = new long[R + 1];
            long[] tableA4 = new long[R + 1];
            long[] table3sA4 = new long[R + 1];
            long[] tableA6 = new long[R + 1];
            long[] table3sA6 = new long[R + 1];
            long[] tableA12 = new long[R + 1];
            long[] table3sA12 = new long[R + 1];
            table[0] = 1;
            table3s[0] = 1;
            for (int i = 1; i <= R; i++)
            {
                if (i >= 2)  // 3s
                {
                    table3s[i] += table[i - 2];
                    table3sA3[i] += tableA3[i - 2];
                    table3sA4[i] += tableA4[i - 2];
                    table3sA6[i] += tableA6[i - 2];
                    table3sA12[i] += tableA12[i - 2];
                }
                if (i >= 2 && C % 3 == 0)  // 122122
                {
                    tableA3[i] += table3s[i - 2];
                    tableA3[i] += 3 * table3sA3[i - 2];
                    tableA12[i] += table3sA4[i - 2];
                    tableA6[i] += 3 * table3sA6[i - 2];
                    tableA12[i] += 3 * table3sA12[i - 2];
                }
                if (i >= 2 && C % 6 == 0)  // 2 layer snake
                {
                    tableA6[i] += table3s[i - 2];
                    tableA6[i] += 3 * table3sA3[i - 2];
                    tableA12[i] += 2 * table3sA4[i - 2];
                    tableA6[i] += 6 * table3sA6[i - 2];
                    tableA12[i] += 6 * table3sA12[i - 2];
                }
                if (i >= 3 && C % 4 == 0)  // 3 layer snake
                {
                    tableA4[i] += table3s[i - 3];
                    tableA12[i] += table3sA3[i - 3];
                    tableA4[i] += 4 * table3sA4[i - 3];
                    tableA12[i] += 2 * table3sA6[i - 3];
                    tableA12[i] += 4 * table3sA12[i - 3];
                }
                if (i >= 1)  // 2s
                {
                    table[i] += table3s[i - 1];
                    tableA3[i] += table3sA3[i - 1];
                    tableA4[i] += table3sA4[i - 1];
                    tableA6[i] += table3sA6[i - 1];
                    tableA12[i] += table3sA12[i - 1];
                }
                table[i] %= M;
                table3s[i] %= M;
                tableA3[i] %= M;
                table3sA3[i] %= M;
                tableA4[i] %= M;
                table3sA4[i] %= M;
                tableA6[i] %= M;
                table3sA6[i] %= M;
                tableA12[i] %= M;
                table3sA12[i] %= M;
            }

            long ans = (table[R] + table3s[R] + tableA3[R] + table3sA3[R] +
                    tableA4[R] + table3sA4[R] + tableA6[R] + table3sA6[R] +
                    tableA12[R] + table3sA12[R]) % M;

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }
}
