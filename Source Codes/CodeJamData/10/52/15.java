
import java.io.File;
import java.io.FileNotFoundException;

import java.util.Arrays;
import java.util.Scanner;

public class B {
    public int gcd(int a,int b)
    {
        if( a > b )
            return gcd(b, a);
        int r = b%a;
        while(r>0)
        {
            b = a;
            a = r;
            r = b%a;
        }
        return a;
    }
    public void solve() throws FileNotFoundException
    {
        Scanner cin = new Scanner( new File("1.txt"));
        //System.setOut( new PrintStream("Bs.txt") );
        int T = cin.nextInt();
        
        for(int cas=1;cas<=T;cas++)
        {
            long L = cin.nextLong();
            int N = cin.nextInt();
            int [] b = new int [N];
            for(int i=0;i<N;i++)
                b[i] = cin.nextInt();
            Arrays.sort(b);
            int g = b[0];
            for(int i=1;i<N;i++)
                g = gcd( g,b[i]);

            if( L%g!=0 )
            {
                System.out.println( "Case #"+cas+": IMPOSSIBLE");
                continue;
            }
            if( N==1 )
            {
                System.out.println( "Case #"+cas+": " + ( L/N ) );
                continue;
            }
            int maxI = b[N-2]*b[N-1] - b[N-2];
            
            long remain = L - maxI;
            long used = 0;
            int solve = 0;
            used = remain / b[N-1];
            solve = (int) (remain% b[N-1]) + maxI; 
//          System.out.println( used + " " + ( used * b[N-1] ) + " " + solve );
            long [] dp = new long[ solve + 1 ];
            for(int j=1;j<=solve;j++)
                dp[j] = solve+1;
            dp[0] = 0;
            for(int i=0;i<N;i++)
                for(int j=0;j<=solve-b[i];j++)
                    dp[ j+b[i] ] =  Math.min( dp[ j+b[i] ], dp[j]+1 );

            
            System.out.println("Case #" + cas + ": "+ (dp[solve] + used));
        }
    }
    public static void main(String[] args) throws FileNotFoundException{
        B b= new B();
        b.solve();
    }
}