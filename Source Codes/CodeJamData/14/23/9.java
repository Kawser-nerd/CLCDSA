import java.io.*;
import java.util.*;
 
class C
{
    static int n;
    static boolean[][] buur;
    static boolean[] vis;
    static int[] stack=new int[100];
    
    static boolean[] kanvis;
    
    static void dfs(int cur)
    {
        kanvis[cur]=true;
        for(int i=0;i<n;i++)
            if(buur[cur][i]&&!kanvis[i])
                dfs(i);
    }

    static boolean kan(int index, int to)
    {
        for(int i=0;i<n;i++)
            kanvis[i]=vis[i];
        for(int i=0;i<=index;i++)
            dfs(stack[i]);
        for(int i=0;i<n;i++)
            if(!kanvis[i])
                return false;
        return true;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int numTests=sc.nextInt();
        for(int test=1;test<=numTests;test++)
        {
            n=sc.nextInt();
            int m=sc.nextInt();

            int[] zip=new int[n];
            vis=new boolean[n];
            buur=new boolean[n][n];
            kanvis=new boolean[n];

            for(int i=0;i<n;i++)
                zip[i]=sc.nextInt();
            for(int i=0;i<m;i++)
            {
                int a=sc.nextInt();
                int b=sc.nextInt();
                a--;
                b--;
                buur[a][b]=buur[b][a]=true;
            }

            int indlo=0;
            for(int i=1;i<n;i++)
                if(zip[i]<zip[indlo])
                    indlo=i;

            String res=""+zip[indlo];
            vis[indlo]=true;
            int ns=0;
            stack[ns++]=indlo;

            for(int rep=1;rep<n;rep++)
            {
                int best=123456789;
                int bi=-1, bj=-1;
                for(int i=ns-1;i>=0;i--)
                    for(int j=0;j<n;j++)
                        if(!vis[j]&&buur[stack[i]][j]&&zip[j]<best&&kan(i,j))
                        {
                            best=zip[j];
                            bi=i;
                            bj=j;
                        }

                res+=best;
                vis[bj]=true;
                ns=bi+1;
                stack[ns++]=bj;
            }

            System.out.println("Case #"+test+": "+res);
        }

    }
}