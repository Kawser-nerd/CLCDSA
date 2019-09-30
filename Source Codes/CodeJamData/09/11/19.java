import java.util.*;
import java.io.*;

public class MultiBase
{
    boolean FILE = true;
    public static void main(String[] args) throws Exception
    {
        new MultiBase();
    }

    public MultiBase() throws Exception
    {
        if(!FILE)
            System.out.println("DON'T FORGET TO REDIRECT TO FILE!");
//        Scanner sc = new Scanner(System.in);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        if(FILE)
        {
//            sc = new Scanner(new File("GCJ.in"));
            in = new BufferedReader(new FileReader("GCJ.in"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("GCJ.out")));
        }

        for(int i = 2; i <= 10; i++)
        {
            used[i][1] = true;
            memo[i][1] = true;
        }
        int T = Integer.parseInt(in.readLine());
        for(int t = 1; t <= T; t++)
        {
            String[] toks = in.readLine().split(" ");
            int B = toks.length;
            int[] bases = new int[B];
            for(int i = 0; i < B; i++)
                bases[i] = Integer.parseInt(toks[i]);

            int ret = -1;
            for(int i = 2; ; i++)
            {
                boolean ok = true;
                for(int b: bases)
                    ok &= happy(b, i);
                if(ok)
                {
                    ret = i;
                    break;
                }
            }

            out.printf("Case #%d: %d\n", t, ret);


        }


        out.close();
        if(!FILE)
            System.out.println("DON'T FORGET TO REDIRECT TO FILE!");
    }


//    boolean[] seen = new boolean[100001];
//    HashMap[] memo = new HashMap[10];
//    boolean happy(int num, int base)
//    {
//        if(base == 2 || base == 4) return true;
//
//        if(memo[base].containsKey(num))
//            return (Boolean)memo[base].get(num);
//        Arrays.fill(seen, false);
//        boolean ret = false;
//        int orig = num;
//        while(true)
//        {
//            seen[num] = true;
//            int v = replace(num, base);
//            if(seen[v])
//            {
//
//                return false;
//            }
//            if(v == 1) return true;
//            if(memo[base].containsKey(num))
//                return (Boolean)memo[base].get(num);
//            num = v;
//        }
//    }


    Stack<Integer> stack = new Stack<Integer>();
    int len = 20000001;
    boolean[][] memo = new boolean[11][len];
    boolean[][] used = new boolean[11][len];
    boolean[][] seen = new boolean[11][len];
    boolean happy(int base, int num)
    {
        if(base == 2 || base == 4) return true;
        if(used[base][num])
            return memo[base][num];

//        System.out.println(base + " " + num);
        int x = num;
        stack.add(x);
        seen[base][x] = true;
        while(true)
        {
//            System.out.println(x);
            int y = replace(x, base);
            if(used[base][y])
            {
                while(!stack.empty())
                {
                    int curr = stack.pop();
                    used[base][curr] = true;
                    memo[base][curr] = memo[base][y];
                }
                return memo[base][y];
            }
            else if(seen[base][y])
            {
                while(!stack.empty())
                {
                    int curr = stack.pop();
                    used[base][curr] = true;
                    memo[base][curr] = false;
                }
                return false;
            }
            seen[base][y] = true;
            stack.add(y);
            x = y;
        }
    }


    int replace(int num, int base)
    {
        int ret = 0;
        while(num > 0)
        {
            int d = num % base;
            ret += d*d;
            num /= base;
        }
        return ret;
    }
}
