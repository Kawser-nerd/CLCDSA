import java.util.*;
import java.io.*;
import java.math.*;

public class b
{
    public static void main(String argv[])throws Exception
    {
        Scanner sc = new Scanner(System.in);
        PrintStream ps = System.out;
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++)
        {
            ps.print("Case #" + t + ": ");
            
            int N = sc.nextInt();

            BigInteger ts[] = new BigInteger[N];
            for(int i = 0; i < N; i++)
                ts[i] = new BigInteger(sc.next());
 
            Arrays.sort(ts);
            
            BigInteger gcd = ts[1].subtract(ts[0]);
            for(int i = 2; i < N; i++)
                gcd = ts[i].subtract(ts[i - 1]).gcd(gcd);

            System.out.println(gcd.subtract(ts[0].mod(gcd)).mod(gcd));
        }
    }
}
