import java.io.*;
import java.util.*;

/**
 * Created by tela on 2017/06/18.
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(in, out);
        out.close();
    }

    static class TaskC {
            public void solve(InputReader in, PrintWriter out) {
                int H, W, h, w = 0;
                H = in.nextInt();
                W = in.nextInt();
                h = in.nextInt();
                w = in.nextInt();

                if(H % h == 0 && W % w ==0){
                    out.println("No");
                }else{
                    out.println("Yes");
                    for(int r = 1; r <=H; r++){
                        for(int c = 1; c <=W; c++){
                            if(r % h == 0 && c % w == 0){
                                out.print(" "+(-1000*w*h+999));
                            }else{
                                out.print(" "+1000);
                            }
                        }
                        out.println("");
                    }
                }
            }
    }


    //input
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

    }
}