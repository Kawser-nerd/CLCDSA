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
            int N = parseInt(br.readLine());
            int[][] S = new int[N][2];
            for(int n = 0; n < N; n++)
            {
                String[] line = br.readLine().split(" ");
                S[n][0] = parseInt(line[0]);
                S[n][1] = parseInt(line[1]);
            }
            
            int count = 0, stars = 0, max, index;
            while(stars < 2 * N)
            {
                for(int n = 0; n < N; n++)
                {
                    if(S[n][1] <= stars)
                    {
                        stars += (S[n][0] > 9000 ? 1 : 2);
                        count++;
                        S[n][0] = S[n][1] = 9001;
                        n = -1;
                    }
                }
                if(stars == 2 * N)
                    break;
                max = -1;
                index = -1;
                for(int n = 0; n < N; n++)
                {
                    if(S[n][0] <= stars && S[n][1] > max)
                    {
                        max = S[n][1];
                        index = n;
                    }
                }
                if(index == -1)
                    break;
                S[index][0] = 9001;
                stars++;
                count++;
            }
            out.println("Case #" + t + ": " + (stars == 2 * N ? count : "Too Bad")); 
        }
    }
}
