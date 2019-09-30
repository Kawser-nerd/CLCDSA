import java.util.*;
import java.io.*;

public class A
{
    static long[] POW10 = new long[20];
    static
    {
        POW10[0] = 1;
        for (int i = 1; i < POW10.length; i++)
            POW10[i] = POW10[i - 1] * 10;
    }

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            String s = input.next();
            long l = Long.parseLong(s);
            boolean zero = l % POW10[s.length() / 2] == 0;
            if (zero)
            {
                l--;
                s = l + "";
            }
            long ans = 0;
            for (int d = 1; d < s.length(); d++)
                ans += POW10[d / 2] + POW10[(d + 1) / 2] - 1;
            String sb = "0" + s.substring(0, s.length() / 2);
            if (s.length() > 1 && Long.parseLong(sb) != POW10[s.length() / 2 - 1])
            {
                ans += Long.parseLong("0" + new StringBuilder(
                            s.substring(0, s.length() / 2)).reverse().toString());
            }
            ans += Long.parseLong("0" + s.substring(s.length() / 2));
            if (zero)
                ans++;

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }
}
