import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()){tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
    public static void main(String []args) throws IOException {
        init(System.in);
        int n=nextInt();
        int A[]=new int [2*n];
        for (int i=0;i<2*n;i++){
            A[i]=nextInt();
        }
        Arrays.sort(A);
        int sum=0;
        for (int i=0;i<2*n;i+=2){
            if(A[i]<A[i+1]){
                sum+=A[i];
            }
            else{
                sum+=A[i+1];
            }
        }
        System.out.println(sum);
    }
}