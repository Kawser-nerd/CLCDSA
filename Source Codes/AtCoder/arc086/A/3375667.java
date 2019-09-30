//encoded utf-8
//tested with jdk 11

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        Reader rd = new Reader(System.in);
        //br.readLine(); return String one line.
        //Integer.parseInt(); String to Integer(Primitive).
        //String[] hoge = str.split(" ", 0);
        int N = rd.nextInt();
        int K = rd.nextInt();
        int counter = 0;
        int[] aNum = new int[N];
        for(int i = 0; i < N; i++){
            aNum[rd.nextInt() - 1] ++;
        }
        Arrays.sort(aNum);
        int ans = 0;
        for(int i = 0; i < N; i ++){
            if(K > 0) K --;
            else ans += aNum[N - i - 1];
        }
        System.out.println(ans);
    }
}

class Reader{
    private BufferedReader br;
    private StringTokenizer st;

    public Reader(InputStream in){
        br = new BufferedReader(new InputStreamReader(in));
        st = null;
    }
    public String nextString() throws IOException{
        while( st==null || !st.hasMoreTokens() )
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException{
        return Integer.parseInt(nextString());
    }
    public long nextLong() throws IOException{
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException{
        return Double.parseDouble(nextString());
    }
}