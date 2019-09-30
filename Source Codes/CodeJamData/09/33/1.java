import java.io.*;
import java.util.*;

/**
 * Created by HREN_VAM.
 */
public class C implements Runnable{

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;
    public static final String filename = "c";

    class State{

        int st;
        int en;

        State(int st, int en){
            this.st = st;
            this.en = en;
        }

        public String toString(){
            return st + " " + en;
        }

        public int hashCode(){
            return toString().hashCode();
        }

        public boolean equals(Object o){
            State temp = (State)o;
            return (st == temp.st) && (en == temp.en);
        }
    }

    HashMap<State, Integer> h;
    int[] pos;

    int search(int st, int en, int start, int end){
        if(st > en)return 0;
        if(st == en){
            return end - start;
        }
        State state = new State(st, en);
        if(h.containsKey(state)){
            return h.get(state);
        }
        int min = 1000000000;
        for(int i = st;i <= en;i ++){
            min = Math.min(min, search(st, i - 1, start, pos[i] - 1) + search(i + 1, en, pos[i] + 1, end) + (end - start));
        }
        h.put(state, min);
        return min;
    }

    public void solve(int testNumber)throws IOException{
        out.print("Case #" + testNumber + ": ");
        h = new HashMap<State, Integer>();
        int n = nextInt();
        int q = nextInt();
        pos = new int[q];
        for(int i = 0;i < q;i ++){
            pos[i] = nextInt() - 1;
        }
        out.println(search(0, pos.length - 1, 0, n - 1));
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
        new Thread(new C()).start();
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