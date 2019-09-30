import java.util.*;
import java.io.*;

public class C
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++)
                arr[i] = input.nextInt();

            int[] data = new int[2 * N];
            for (int i = 0; i < N; i++)
                data[arr[i] - i + N]++;
            double score = 0;
            for (int i = 700; i < 1000; i++)
                score += data[i];
            for (int i = 1000; i < 1300; i++)
                score -= data[i];
            boolean good = score > -40;

            System.out.printf("Case #%d: ", n + 1);
            if (good)
                System.out.println("GOOD");
            else
                System.out.println("BAD");
        }
    }
}
