import java.util.*;
import java.io.*;

public class B
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            int K = input.nextInt();
            int[] sums = new int[N - K + 1];
            for (int i = 0; i < N - K + 1; i++)
                sums[i] = input.nextInt();

            int[] maxdiffs = new int[K];
            int[] mindiffs = new int[K];
            int[] currdiff = new int[K];
            for (int i = K; i < N; i++)
            {
                currdiff[i % K] += sums[i - K + 1] - sums[i - K];
                if (currdiff[i % K] > maxdiffs[i % K])
                    maxdiffs[i % K] = currdiff[i % K];
                if (currdiff[i % K] < mindiffs[i % K])
                    mindiffs[i % K] = currdiff[i % K];
            }

            int[] diffdiffs = new int[K];
            for (int i = 0; i < K; i++)
                diffdiffs[i] = maxdiffs[i] - mindiffs[i];

            int maxdiffdiff = 0;
            for (int i = 0; i < K; i++)
                if (diffdiffs[i] > maxdiffdiff)
                    maxdiffdiff = diffdiffs[i];
            int highBound = 0;
            for (int i = 0; i < K; i++)
                highBound += maxdiffdiff - diffdiffs[i];

            int target = sums[0];
            for (int i = 0; i < K; i++)
                target += mindiffs[i];
            target = (target % K + K) % K;

            int ans = maxdiffdiff + (target <= highBound ? 0 : 1);

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }
}
