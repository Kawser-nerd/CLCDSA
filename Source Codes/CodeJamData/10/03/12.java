import java.io.*;
import java.lang.*;

public class ThemePark {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new  FileReader("C-large.in" ));
        PrintStream out = new PrintStream(new FileOutputStream("C-large.out"));
        
        long T = Integer.parseInt(in.readLine());
        
        String[] s;
        long R, k;
        int N;
        long[] g = new long[1000], value = new long[1000];
        int[] next = new int[1000];
        
        for (int cas = 1; cas <= T; ++cas) {
            s = in.readLine().split(" ");
            
            R = Long.parseLong(s[0]);
            k = Long.parseLong(s[1]);
            N = Integer.parseInt(s[2]);
            
            s = in.readLine().split(" ");
            
            for (int i = 0; i < N; ++i)
                g[i] = Long.parseLong(s[i]);
                

            for (int i = 0; i < N; ++i) {
                value[i] = g[i];
                next[i] = (i+1) % N;
                
                while (next[i] != i && value[i] + g[next[i]] <= k) {
                    value[i] += g[next[i]];
                    next[i] = (next[i]+1) % N;
                }
            }
            
            long euros = 0;
            int group = 0;
            for (int i = 0; i < R; ++i) {
                euros += value[group];
                group = next[group];
            }
            
            out.println("Case #" + cas + ": " + euros);
        }
        
        in.close();
        out.close();
    }
}
