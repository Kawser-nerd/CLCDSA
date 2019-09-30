import java.io.*;
import java.lang.*;

public class SnapperChain {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new  FileReader("A-large.in" ));
        PrintStream out = new PrintStream(new FileOutputStream("A-large.out"));
        
        int T = Integer.parseInt(in.readLine());
        
        String[] s;
        int N, K, on;
        
        for (int cas = 1; cas <= T; ++cas) {
            s = in.readLine().split(" ");
            
            N = Integer.parseInt(s[0]);
            K = Integer.parseInt(s[1]);
            
            if ((K % (1 << N)) == (1 << N) - 1)
                out.println("Case #" + cas + ": ON");
            else
                out.println("Case #" + cas + ": OFF");
        }
        
        in.close();
        out.close();
    }
}
