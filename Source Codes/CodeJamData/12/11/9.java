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

public class A
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int T = parseInt(br.readLine());
        for(int t = 0; t++ < T; )
        {
            String[] line = br.readLine().split(" ");
            int A = parseInt(line[0]), B = parseInt(line[1]);
            line = br.readLine().split(" ");
            double[] P = new double[A+1];
            P[0] = 1;
            for(int a = 0; a < A; a++)
                P[a+1] = parseDouble(line[a]) * P[a];
            
            // start with hitting enter and retyping password
            double best = 2 + B;
            
            
            for(int a = 0; a <= A; a++)
                // delete a characters and try that
                best = min(best, 2 * a + (B - A) + 1 + (1 - P[A - a]) * (B + 1));
            out.println("Case #" + t +": " + best); 
        }
    }
}
