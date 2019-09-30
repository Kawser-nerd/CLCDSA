import java.io.*;
import java.util.Deque;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader inputReader=new InputReader(System.in);
        PrintWriter printWriter=new PrintWriter(System.out);
        Deque<Integer> deque=new ArrayDeque<>();
        int n;
        n=inputReader.nextInt();
        for(int i=1;i<=n;i++){
            if((i+1)%2==1){
                deque.addFirst(inputReader.nextInt());
            }else{
                deque.addLast(inputReader.nextInt());
            }
        }
        if(n%2==0){
            for(Integer i:deque){
                System.out.print(i.toString()+" ");
            }
        }else{
            for(int i=1;i<=n;i++){
                System.out.print(deque.removeLast().toString()+" ");
            }
        }
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

    }
}