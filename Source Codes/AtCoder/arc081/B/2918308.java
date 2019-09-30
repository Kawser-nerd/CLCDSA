import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Math;

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            tokenizer = new StringTokenizer(reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static long nextLong() throws IOException {
        return Long.parseLong( next() );
    }

    static char nextChar() throws IOException {
        return next().charAt(0);
    }
}

public class Main{
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n=Reader.nextInt();
        String s=Reader.next();
        String p=Reader.next();
        int c=0,mod=1000000007;
        long ans=1;
        for(int i=0;i<n;){
            if(c==0){
                ans*=3;
                if(s.charAt(i)==p.charAt(i)){
                    i++;
                    c=1;
                }
                else{
                    ans*=2;
                    i+=2;
                    c=2;
                }
            }
            else if(c==1){
                if(s.charAt(i)==p.charAt(i)){
                    ans*=2;
                    i++;
                    c=1;
                }
                else {
                    ans*=2;
                    i+=2;
                    c=2;
                }
            }
            else{
                if(s.charAt(i)==p.charAt(i)){
                    i++;
                    c=1;
                }
                else{
                    ans*=3;
                    i+=2;
                    c=2;
                }
            }
            ans=ans%mod;
        }
        System.out.println(ans);
    }
}