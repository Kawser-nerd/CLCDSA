import java.io.*;
import java.util.*;
 
class B
{
    static int a,b,k;
    
    static long[][][][] mem;

    static long go(int ind, int aa, int bb, int kk)
    {
        if(ind==-1)
            return 1;
        if(mem[ind][aa][bb][kk]!=-1)
            return mem[ind][aa][bb][kk];
        long res=0;
        res+=go(ind-1,(~a>>ind)&aa,(~b>>ind)&bb,(~k>>ind)&kk);
        if(aa==0 || (a>>ind)%2==1)
            res+=go(ind-1,(a>>ind)&aa,(~b>>ind)&bb,(~k>>ind)&kk);
        if(bb==0 || (b>>ind)%2==1)
            res+=go(ind-1,(~a>>ind)&aa,(b>>ind)&bb,(~k>>ind)&kk);
        if( (aa==0 || (a>>ind)%2==1) && (bb==0 || (b>>ind)%2==1) && (kk==0 || (k>>ind)%2==1))
            res+=go(ind-1,(a>>ind)&aa,(b>>ind)&bb,(k>>ind)&kk);
        return mem[ind][aa][bb][kk]=res;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int numTests=sc.nextInt();
        for(int test=1;test<=numTests;test++)
        {
            a=sc.nextInt();
            b=sc.nextInt();
            k=sc.nextInt();
            a--;
            b--;
            k--;

            mem=new long[32][2][2][2];
            for(int i=0;i<32;i++)
            for(int j=0;j<2;j++)
            for(int g=0;g<2;g++)
                mem[i][j][g][0]=mem[i][j][g][1]=-1;
            long res=go(31,1,1,1);
            System.out.println("Case #"+test+": "+res);
        }

    }
}