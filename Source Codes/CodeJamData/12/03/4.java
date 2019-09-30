import java.io.*;

public class C {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; c++)
        {
            String[] line = in.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            
            int len = line[0].length();
            int tenlen = 1;
            for (int i=1; i<len; i++)
                tenlen *= 10;
            
            int result = 0;
            for (int n=a; n<b; n++)
            {
                int m = n;
                do
                {
                    m = m / 10 + m % 10 * tenlen;
                    if (m > n && m <= b)
                        result++;
                } while (m != n);
            }
            
            System.out.println("Case #"+c+": "+result);
        }
    }
    
}
