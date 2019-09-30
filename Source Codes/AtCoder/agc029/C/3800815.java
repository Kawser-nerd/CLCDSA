import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;

public class Main implements Runnable {
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars==-1) 
                throw new InputMismatchException();
            
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                }
                catch (IOException e) {
                    throw new InputMismatchException();
                }
                
                if(numChars <= 0)               
                    return -1;
            }
            return buf[curChar++];
        }
     
        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt() {
            int c = read();
            
            while(isSpaceChar(c)) 
                c = read();
            
            int sgn = 1;
            
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            
            int res = 0;
            do {
                if(c<'0'||c>'9') 
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c)); 
            
            return res * sgn;
        }
        
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
                return res * sgn;
        }
        
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        
        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } 
            while (!isSpaceChar(c));
            
            return res.toString();
        }
     
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
     
        public String next() {
            return readString();
        }
        
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
    public static void main(String args[]) throws Exception {
        new Thread(null, new Main(),"Main",1<<26).start();
    }
    int queryBit(int ind) {
        int ans = 0;
        while(ind > 0) {
            ans = max(ans, bit[ind]);
            ind -= Integer.lowestOneBit(ind);
        }
        return ans;
    }

    void updateBit(int ind, int time) {
        while(ind < bit.length) {
            bit[ind] = max(bit[ind], time);
            ind += Integer.lowestOneBit(ind);
        }
    }
    void add(int[] val, int ind, int lim) {
        int flag = 0;

        while(ind > 0) {
            if(queryBit(ind + 1) > lastTime[ind])
                val[ind] = 0;

            lastTime[ind] = time;
            if(val[ind] == lim - 1) {
                val[ind] = 0;
            }
            else {
                val[ind]++;
                flag = 1;
                break;
            }

            ind--;
        }

        if(flag == 0)
            val[0]++;
    }
    int bit[];
    int time;
    int lastTime[];
    public void run() {
        try {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = sc.nextInt();

        long a[] = new long[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextLong();

        int flag = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i] <= a[i - 1])
                flag = 1;
        }

        if(flag == 0) {
            w.print("1");
            w.close();
            return;
        }

        lastTime = new int[2 * n];
        int val[] = new int[2 * n];
        bit = new int[2 * n + 1];

        int start = 2, end = n, ans = n;
        while(start <= end) {
            int mid = (start + end) >> 1;

            time = 0;
            Arrays.fill(lastTime, 0);
            Arrays.fill(val, 0);
            Arrays.fill(bit, 0);

            for(int i = 1; i < n; ++i) {
                time++;
                if(a[i] > a[i - 1]) {
                    if(a[i - 1] < 2 * n) {
                        updateBit((int)(a[i - 1] + 1), time);
                    }
                }
                else {
                    add(val, (int)min(a[i] - 1, 2 * n - 1), mid);
                }
            }       

            if(val[0] < mid) {
                ans = mid;
                end = mid - 1;
            }     
            else
                start = mid + 1;
        } 

        w.print(ans);

        w.close(); } catch(Exception e) {System.out.println(e.toString());}
    }
}