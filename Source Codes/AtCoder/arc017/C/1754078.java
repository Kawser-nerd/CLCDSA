import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        long x = scan.nextInt();
        long[] w=new long[n];
        for(int i=0;i<n;++i)
            w[i]=scan.nextInt();
        int m=n/2;
        long[]f=new long[1<<m];
        long[]s=new long[1<<n-m];
        for(int i=0;i<1<<m;++i)
            for(int j=0;j<m;++j)
                if((i&1<<j)!=0)f[i]+=w[j];
        for(int i=0;i<1<<n-m;++i)
            for(int j=0;j<n-m;++j)
                if((i&1<<j)!=0)s[i]+=w[m+j];
        Map<Long,Integer>hs=new HashMap<Long,Integer>();
        for(long ss:s)
            if(!hs.containsKey(ss))
                hs.put(ss,1);
            else
                hs.put(ss,hs.get(ss)+1);
        long total=0;
        for(long ff:f)
            if(hs.containsKey(x-ff))
                total+=hs.get(x-ff);
        System.out.println(total);
    }
}