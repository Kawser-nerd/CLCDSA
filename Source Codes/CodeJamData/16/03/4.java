import java.util.*;
import java.lang.Math;
import java.io.*;
import java.math.*;

class Main
{
    static boolean pr(BigInteger N) 
    {
        for (long i = 2; i * i <= 1000000000; ++i)
        {
            BigInteger X = BigInteger.valueOf(i);
            if (N.equals(X)) break;
            if (N.mod(X) == BigInteger.valueOf(0)) {
                return false;
            }
        }
        return true;
    }
    static void pr2(BigInteger N) 
    {
        for (long i = 2; i * i <= 1000000000; ++i)
        {
            BigInteger X = BigInteger.valueOf(i);
            if (N.equals(X)) break;
            if (N.mod(X) == BigInteger.valueOf(0)) {
                System.out.print(" " + i);
                return;
            }
        }
    }
	public static void main (String[] args)
	{
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
		int T = in.nextInt();
        int N = in.nextInt();
        int J = in.nextInt();
        int risan = 0;
        System.out.println("Case #1:");
        for (int i = 0; i < 1 << (N - 2); ++i){
            String s = "";
            for (int j = 0; j < N - 2; ++j){
                if ((i & (1 << j)) > 0) s += '1';
                else s += '0';
            }
            s = '1' + s + '1';
            //System.out.println(s);
            boolean r = true;
            for (int j = 2; j <= 10; ++j)
            {
                BigInteger X = new BigInteger(s,j);
                //System.out.println(s + " " + X);
                if (pr(X)) r = false;
            }
            if (r == false) continue;
            System.out.print(s);
            for (int j = 2; j <= 10; ++j)
            {
                BigInteger X = new BigInteger(s,j);
                pr2(X);
            }
            System.out.println("");
            ++risan;
            if (risan == J) break;
            hell:;
        }
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}
