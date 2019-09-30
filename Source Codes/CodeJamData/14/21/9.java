import java.io.*;
import java.util.*;
 
class A
{
    static int calc(int[] q)
    {
        int res=1234567;
        for(int a=0;a<=100;a++)
        {
            int cur=0;
            for(int i=0;i<q.length;i++)
                cur+=Math.abs(q[i]-a);
            res=Math.min(res,cur);
        }
        return res;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int numTests=sc.nextInt();
        for(int test=1;test<=numTests;test++)
        {
            int n=sc.nextInt();
            String must="";
            int[][] q=new int[111][n];
            for(int i=0;i<n;i++)
            {
                String s=sc.next()+"?";
                String t="";
                int ind=0;
                char c='?';
                int cnt=1;
                for(int j=0;j<s.length();j++)
                {
                    if(s.charAt(j)==c)
                        cnt++;
                    else
                    {
                        t+=c;
                        q[ind][i]=cnt;
                        cnt=0;
                        ind++;
                        c=s.charAt(j);
                    }
                }
                if(i==0)
                    must=t;
                else if(!must.equals(t))
                    must="?";
            }
            
            String lost="Fegla Won";
            if(must.equals("?"))
            {
                System.out.println("Case #"+test+": "+lost);
            }
            else
            {
                int res=0;
                for(int i=0;i<111;i++)
                    res+=calc(q[i]);
                System.out.println("Case #"+test+": "+res);
            }
        }

    }
}