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

public class B
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for(int t = 0; t++ < T; )
        {
            String[] line = br.readLine().split(" ");
            int N = parseInt(line[0]);
            int S = parseInt(line[1]);
            int p = parseInt(line[2]);
            int C = 0;
            for(int n = 0; n < N; ++n)
            {
                int g = parseInt(line[n + 3]);
                if(3*p - 2 <= g)
                    C++;
                else if((p == 1 ? 1 : 3*p - 4) <= g && S != 0)
                {
                    C++;
                    S--;
                }
            }
            out.println("Case #" + t +": " + C); 
        }
    }
}
