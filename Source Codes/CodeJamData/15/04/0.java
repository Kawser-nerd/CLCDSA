import java.util.*;
import java.io.*;

public class D
{
    static int N, R, C;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();
            R = input.nextInt();
            C = input.nextInt();

            System.out.printf("Case #%d: %s\n", n + 1, good() ? "GABRIEL" : "RICHARD");
        }
    }

    static boolean good()
    {
        if (R * C % N != 0)
            return false;

        if (N >= 7)
            return false;
        else if (N == 6)
        {
            if (Math.min(R, C) <= 3)
                return false;
        }
        else if (N == 5)
        {
            if (Math.min(R, C) <= 2 ||
                    Math.min(R, C) == 3 && Math.max(R, C) == 5)
                return false;
        }
        else if (N == 4)
        {
            if (Math.min(R, C) <= 2)
                return false;
        }
        else if (N == 3)
        {
            if (Math.min(R, C) <= 1)
                return false;
        }
        return true;
    }
}
