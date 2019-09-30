import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            int k=nextInt();
            double[] a=new double[n];
            for(int i=0;i<n;i++)a[i]=nextDouble();
            Arrays.sort(a);
            int l=k;
            int r=0;
            double bestProb=0;
            for(int q=0;q<=k;q++,l--,r++){
                double[] p=new double[k];
                int w=0;
                for(int i=0;i<l;i++)p[w++]=a[i];
                for(int i=0;i<r;i++)p[w++]=a[n-i-1];

                double[][] dp=new double[k+1][k+1];
                dp[0][0]=1;
                for(int i=0;i<k;i++)
                    for(int j=0;j<k;j++)
                        if(dp[i][j]!=0){
                            dp[i+1][j]+=dp[i][j]*p[i];
                            dp[i+1][j+1]+=dp[i][j]*(1-p[i]);
                        }
                bestProb=Math.max(bestProb,dp[k][k/2]);
            }
            out.printf(Locale.CANADA,"Case #%d: %.9f\n",testCase+1,bestProb);

        }
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
