import java.util.*;

public class D
{
    static boolean[] dp;
    static int[] keys;
    static Stack<Integer> st;
    static String ans;
    static int K, N;
    static int[][] con;
    static int[] type;

    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            K = scan.nextInt();
            N = scan.nextInt();
            dp = new boolean[1 << N];
            keys = new int[201];
            st = new Stack<Integer>();
            ans = null;
            con = new int[N][];
            type = new int[N];

            for(int i=0;i < K;i++)
                keys[scan.nextInt()]++;
            for(int i=0;i < N;i++)
            {
                type[i] = scan.nextInt();
                int k = scan.nextInt();
                con[i] = new int[k];
                for(int j=0;j < k;j++)
                    con[i][j] = scan.nextInt(); 
            }

            f(0);

            System.out.println("Case #" + ca + ":" + (ans == null ? " IMPOSSIBLE" : ans));
        }
    }


    public static void f(int mask)
    {
        if(dp[mask]) return;
        if(ans != null) return;

        if(mask == (1 << N)-1)
        {
            ans = "";
            while(!st.empty())
                ans = " " + st.pop() + ans;
            dp[mask] = true;
            return;
        }

        for(int i=0;i < N;i++)
        {
            if(keys[type[i]] == 0) continue;
            if((mask & (1 << i)) > 0) continue;

            keys[type[i]]--;
            st.push(i+1);
            int newmask = mask | (1 << i);
            for(int j=0;j < con[i].length;j++)
                keys[con[i][j]]++;

            f(newmask);

            keys[type[i]]++;
            if(!st.empty()) st.pop();
            for(int j=0;j < con[i].length;j++)
                keys[con[i][j]]--;
        }

        dp[mask] = true;
    }
}