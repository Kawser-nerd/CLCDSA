import java.util.*;
import java.io.*;

public class A
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            String s = input.next();

            int total = 0, numFriends = 0;
            for (int i = 0; i <= N; i++)
            {
                int d = s.charAt(i) - '0';
                if (d > 0 && total < i)
                {
                    numFriends += i - total;
                    total = i;
                }
                total += d;
            }
            System.out.printf("Case #%d: %d\n", n + 1, numFriends);
        }
    }
}
