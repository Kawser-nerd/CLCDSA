import java.util.*;
import java.io.*;

public class C
{
    static int N;

    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int X = input.nextInt();
            int Y = input.nextInt();
            int Z = input.nextInt();
            int K = input.nextInt();

            System.out.printf("Case #%d: ", n + 1);
            if (K >= Z)
            {
                System.out.println(X * Y * Z);
                for (int i = 0; i < X; i++)
                    for (int j = 0; j < Y; j++)
                        for (int k = 0; k < Z; k++)
                            System.out.println((i + 1) + " " + (j + 1) + " " + (k + 1));
            }
            else if (K >= Y)
            {
                System.out.println(X * Y * K);
                for (int i = 0; i < X; i++)
                    for (int j = 0; j < Y; j++)
                        for (int k = 0; k < K; k++)
                            System.out.println((i + 1) + " " + (j + 1) + " " + (k + 1));
            }
            else
            {
                System.out.println(K * X * Y);
                for (int i = 0; i < Y; i++)
                    for (int j = 0; j < X; j++)
                        for (int k = 0; k < K; k++)
                            System.out.println((j + 1) + " " + ((i + j + k) % Y + 1) + " " + (i + 1));
            }
        }
    }
}
