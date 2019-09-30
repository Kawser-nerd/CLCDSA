import java.io.*;
import java.util.*;

/**
 * Created by HREN_VAM.
 */
public class A implements Runnable{

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;
    public static final String filename = "a";
    
    public void solve(int testNumber)throws IOException{
        out.print("Case #" + testNumber + ": ");
        int base = 0;
        HashMap<Character, Integer> h = new HashMap<Character, Integer>();
        String s = nextToken();
        h.put(s.charAt(0), 1);
        for(int i = 1;i < s.length();i ++){
            if(!h.containsKey(s.charAt(i))){
                h.put(s.charAt(i), base);
                base ++;
                if(base == 1)base ++;
            }
        }
        if(base < 2)base = 2;
        long res = 0;
        long pow = 1;
        for(int i = s.length() - 1;i >= 0;i --){
            res += h.get(s.charAt(i)) * pow;
            pow *= base;
        }
        out.println(res);
    }    
    
    public void run(){
        try{
            Locale.setDefault(Locale.US);
            //in = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new PrintWriter(System.out);
            out = new PrintWriter(new FileWriter(filename + ".out"));
            st = new StringTokenizer("");
            int t = nextInt();
            for(int i = 0;i < t;i ++){
                solve(i + 1);
            }
            out.close();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }
    
    public static void main(String[] args){
        new Thread(new A()).start();
    }
    
    public String nextToken()throws IOException{
        while(!st.hasMoreTokens()){
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    
    public int nextInt()throws IOException{
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble()throws IOException{
        return Double.parseDouble(nextToken());
    }
}