import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;
public class Main 
{
    static class Scanner
    {
        BufferedReader br;
        StringTokenizer tk=new StringTokenizer("");
        public Scanner(InputStream is) 
        {
            br=new BufferedReader(new InputStreamReader(is));
        }
        public int nextInt() throws IOException
        {
            if(tk.hasMoreTokens())
                return Integer.parseInt(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextInt();
        }
        public long nextLong() throws IOException
        {
            if(tk.hasMoreTokens())
                return Long.parseLong(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextLong();
        }
        public String next() throws IOException
        {
            if(tk.hasMoreTokens())
                return (tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return next();
        }
        public String nextLine() throws IOException
        {
            tk=new StringTokenizer("");
            return br.readLine();
        }
        public double nextDouble() throws IOException
        {
            if(tk.hasMoreTokens())
                return Double.parseDouble(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextDouble();
        }
        public char nextChar() throws IOException
        {
            if(tk.hasMoreTokens())
                return (tk.nextToken().charAt(0));
            tk=new StringTokenizer(br.readLine());
            return nextChar();
        }
        public int[] nextIntArray(int n) throws IOException
        {
            int a[]=new int[n];
            for(int i=0;i<n;i++)
                a[i]=nextInt();
            return a;
        }
        public long[] nextLongArray(int n) throws IOException
        {
            long a[]=new long[n];
            for(int i=0;i<n;i++)
                a[i]=nextLong();
            return a;
        }
        public int[] nextIntArrayOneBased(int n) throws IOException
        {
            int a[]=new int[n+1];
            for(int i=1;i<=n;i++)
                a[i]=nextInt();
            return a;
        }
        public long[] nextLongArrayOneBased(int n) throws IOException
        {
            long a[]=new long[n+1];
            for(int i=1;i<=n;i++)
                a[i]=nextLong();
            return a;
        }
    
    
    }
    
    public static void main(String args[]) throws IOException
    {
        Scanner in=new Scanner(System.in);
        PrintWriter out=new PrintWriter(System.out);
        int n=in.nextInt();
        int b[]=new int[n+1];
        int w[]=new int[n+1];
        for(int i=1;i<=2*n;i++)
        {
            if(in.nextChar()=='B')
                b[in.nextInt()]=i;
            else
                w[in.nextInt()]=i;
        }
        int lb[][]=new int[2*n+2][n+2];
        int lw[][]=new int[2*n+2][n+2];
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                lb[i][j]=lb[i][j-1]+((b[j]<i)?1:0);
                lw[i][j]=lw[i][j-1]+((w[j]<i)?1:0);
            }
        }
        int dp[][]=new int[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0]+(b[i]-lb[b[i]][i]-1);
        }
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=dp[0][i-1]+(w[i]-lw[w[i]][i]-1);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=Math.min(dp[i-1][j]+b[i]-lb[b[i]][i-1]-lw[b[i]][j]-1,dp[i][j-1]+w[j]-lw[w[j]][j-1]-lb[w[j]][i]-1);
            }
        }
        out.println(dp[n][n]);
        out.close();
    }

}