import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.HashMap;

class Main{

    static long C=20000*20000;
    static long B=20000;
    static long A=1;

    static long baseC = (long)1e8;
    static long baseB = (long)1e4;
    static long baseA = (long)1e4;

    static long mod =998244353;

    static int gcd(int x, int y){
        return y==0 ? x : gcd( y, x%y);
    }

    static long getVal(int a, int b,int c){
        int m = gcd(a, gcd(Math.abs(b),Math.abs(c)));
        a/=m; b/=m; c/=m;
        return ((long)c+baseC)*C + ((long)b + baseB)*B +((long)a + baseA)*A;
    }

    static long getLine(int x1,int y1,int x2, int y2){
        if(x1==x2)return getVal(1, 0, -x1);
        
        if(y2-y1<0){
            int tmp = y1;y1=y2;y2=tmp;
            tmp=x1;x1=x2;x2=tmp;
        }else if(y2-y1==0 && x2-x1<0){
            int tmp = x1;x1=x2;x2=tmp;
        }
        return getVal(y2-y1, x2-x1, y2*x1-y1*x2);
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        for(int i=0;i<N;++i){
            x[i]=scan.nextInt();
            y[i]= scan.nextInt();
        }
        long two[] = new long[N+1];
        two[0]=1;
        for(int i=1;i<=N;++i)two[i]=(two[i-1]*2)%mod;

        long ans = two[N];
        ans = (ans - (N*(N-1)/2) - N -1 +mod)%mod;

        Set<Long> used = new HashSet<>();
        for(int i=0;i<N;++i){
            Map<Long, Integer> line = new HashMap<>();
            for(int j=i+1;j<N;++j){
                long l = getLine(x[i], y[i], x[j], y[j]);
                if(used.contains(l))continue;
                if(!line.containsKey(l))line.put(l,0);
                line.put(l, line.get(l)+1);
            }
            for(Map.Entry<Long, Integer> entry : line.entrySet()){
                if(entry.getValue() >1){
                    int k = entry.getValue()+1;
                    ans = (ans - (two[k] - (k*(k-1)/2 +k +1) +mod)%mod +mod)%mod;
                    used.add(entry.getKey());
                }
            }
        }
        System.out.println(ans);
    }
}