import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Ceasy {

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int N=nextInt();
            int[] d=new int[N];
            int[] n=new int[N];
            int[] w=new int[N];
            int[] e=new int[N];
            int[] s=new int[N];
            int[] deltaD=new int[N];
            int[] deltaP=new int[N];
            int[] deltaS=new int[N];
            int[] count=new int[N];
            for(int i=0;i<N;i++){
                d[i]=nextInt();
                n[i]=nextInt();
                w[i]=nextInt();
                e[i]=nextInt();
                s[i]=nextInt();
                deltaD[i]=nextInt();
                deltaP[i]=nextInt();
                deltaS[i]=nextInt();
                count[i]=0;
            }
            int[] x=new int[2000];
            int shift=1000;
            int ans=0;
            while(true){
                int cur=-1;
                for(int i=0;i<N;i++){
                    if((cur==-1||(cur>d[i]))&&n[i]>count[i]){
                        cur=d[i];
                    }
                }
                if(cur==-1)break;
                for(int i=0;i<N;i++){
                    if(d[i]==cur&&n[i]>count[i]){
                        for(int j=w[i];j<e[i];j++)
                            if(x[j+shift]<s[i]){
                                ans++;
                                break;
                            }
                    }
                }
                for(int i=0;i<N;i++){
                    if(d[i]==cur&&n[i]>count[i]){
                        for(int j=w[i];j<e[i];j++)
                            if(x[j+shift]<s[i])
                                x[j+shift]=s[i];
                        d[i]+=deltaD[i];
                        s[i]+=deltaS[i];
                        e[i]+=deltaP[i];
                        w[i]+=deltaP[i];
                        count[i]++;
                    }
                }
            }
            out.printf("Case #%d: %d\n",testCase+1,ans);

        }

    }

    public static void main(String[] args) throws IOException {
        new Ceasy().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
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