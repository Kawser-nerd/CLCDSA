import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.math.BigDecimal;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int A = in.nextInt();
            int B = in.nextInt();
            int C = in.nextInt();
            int D = in.nextInt();
            int E = in.nextInt();
            int F = in.nextInt();
            double P = (double)(100*E)/(100+E);
            double min=1000;
            int X=0;
            int Y=0;
            for(int i=0; i<=30; i++){
                if(A*i*100>F) break;
                for(int j=0; j<=30; j++){
                    if(A*i*100+B*j*100>F) break;
                    for(int k=0; k<=3000; k++){
                        if(A*i*100+B*j*100+C*k>F) break;
                        for(int m=0; m<=3000; m++){
                            if(A*i*100+B*j*100+C*k+D*m>F) break;
                            int L=A*i*100+B*j*100;
                            int S=C*k+D*m;
                            if(L==0) break;
                            double P1 = (double)(100*S)/(L+S);
                            if(P-P1>=0&&P-P1<min){
                                min=P-P1;
                                X=L;
                                Y=S;
                            }
                        }
                    }
                }
            }
            out.println(X+Y+" "+Y);
            
        }
    }

    private static long gcd(long m, long n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }

    private static long lcm(long m, long n) {
        return m * (n /gcd(m, n));
    }


    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}