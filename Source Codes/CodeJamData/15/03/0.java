import java.util.*;
import java.io.*;

public class C
{
    public static void main(String ... orange) throws Exception
    {
//        System.out.println(mult("1", "
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            long N = input.nextLong();
            long X = input.nextLong();
            String s = input.next();

            String curr = "1";
            for (int i = 0; i < N; i++)
            {
                String t = s.charAt(i) + "";
                curr = mult(curr, t);
            }
//            System.out.println("curr: " + curr);
            String all = "1";
            for (int j = 0; j < X % 4; j++)
                all = mult(all, curr);
//            System.out.println("all: " + all);
            int bestLeft = -1, bestRight = -1;
            curr = "1";
            for (int i = 0; i < N * X && i < 4 * N; i++)
            {
                String t = s.charAt((int) (i % N)) + "";
                curr = mult(curr, t);
                if (curr.equals("i"))
                {
                    bestLeft = i + 1;
                    break;
                }
            }
            curr = "1";
            for (int i = 0; i < N * X && i < 4 * N; i++)
            {
                String t = s.charAt((int) (N - 1 - i % N)) + "";
                curr = mult(t, curr);
                if (curr.equals("k"))
                {
                    bestRight = i + 1;
                    break;
                }
            }
//            System.out.println("bestLeft: " + bestLeft);
//            System.out.println("bestRight: " + bestRight);
            boolean good = all.equals("-1") && bestLeft != -1 && bestRight != -1 && bestLeft + bestRight < N * X;
            System.out.printf("Case #%d: %s\n", n + 1, good ? "YES" : "NO");
        }
    }

    static String mult(String a, String b)
    {
        boolean neg = false;
        if (a.charAt(0) == '-')
        {
            a = a.substring(1);
            neg ^= true;
        }
        if (b.charAt(0) == '-')
        {
            b = b.substring(1);
            neg ^= true;
        }
        String ans;
        if (a.equals("1"))
            ans = b;
        else if (b.equals("1"))
            ans = a;
        else if (a.equals(b))
            ans = "-1";
        else if (a.equals("i"))
            ans = b.equals("j") ? "k" : "-j";
        else if (a.equals("j"))
            ans = b.equals("i") ? "-k" : "i";
        else
            ans = b.equals("i") ? "j" : "-i";
        if (ans.charAt(0) == '-')
        {
            ans = ans.substring(1);
            neg ^= true;
        }
        if (neg)
            ans = "-" + ans;
        return ans;
    }
}


