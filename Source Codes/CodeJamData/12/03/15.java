import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;
import static java.lang.Math.*;
import static java.lang.Integer.parseInt;
import static java.lang.Double.parseDouble;
import static java.lang.Long.parseLong;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collection.*;

public class C
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for(int t = 0; t++ < T; )
        {
            String[] line = br.readLine().split(" ");
            int A = parseInt(line[0]), B = parseInt(line[1]);
            long[] V = new long[B - A + 1], S = new long[B - A + 1];
            int order = 1;
            S[0] = V[0] = 0;
            while(order < B) order *= 10;
            
            for(int i = A + 1; i <= B; i++)
            {
                int index = -1;
                for(int j = 10; j <= i; j *= 10)
                {
                    int count = i / j + (i % j) * (order / j);
                    if(index < count && count < i)
                        index = count;
                }
                V[i - A] = index >= A ? V[index - A] + 1 : 0;
                S[i - A] = V[i - A] + S[i - A - 1];
            }
            out.println("Case #" + t +": " + S[B-A]) ; 
        }
    }
}
