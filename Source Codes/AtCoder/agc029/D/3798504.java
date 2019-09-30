import java.util.*;
import java.io.*; 
import java.text.*;
//Solution Credits: Taranpreet Singh
public class Main{
    //SOLUTION BEGIN
    void solve(int TC) throws Exception{
        int h = ni(), w = ni(), n = ni();
        TreeSet<Integer>[] set = new TreeSet[w];
        for(int i = 0; i< w; i++){
            set[i] = new TreeSet<>();
            set[i].add(h);
        }
        for(int i = 0; i< n; i++){
            int x = ni()-1, y = ni()-1;
//            set[y].add(x);
            set[y].add(x);
        }
        if(set[0].contains(1)){
            pn(1);
            return;
        }
        int ans = INF;
        int x = 0, y = 0;
        int[] min = new int[w];
        Arrays.fill(min, -1);
        min[0] = 0;
        for(int i = 0; i< w-1; i++){
            if(set[y].contains(x+1))break;
            x++;
            while(x< h && !set[y].contains(x+1) && set[y+1].contains(x))x++;
            if(set[y+1].contains(x))break;
            min[y+1] = x;
            y++;
        }
        for(int i = 0; i< w; i++)if(min[i]!=-1){
            int val = set[i].ceiling(min[i]);
            ans = Math.min(ans, val);
        }
        pn(ans);
    }
    //SOLUTION END
    long MOD = (long)1e9+7, IINF = (long)1e9+5;
    final int INF = (int)2e9, MAX = (int)2e5+1;
    DecimalFormat df = new DecimalFormat("0.0000000000");
    double PI = 3.1415926535897932384626433832792884197169399375105820974944, eps = 1e-8;
    static boolean multipleTC = false, memory = false;
    FastReader in;PrintWriter out;
    void run() throws Exception{
        in = new FastReader();
        out = new PrintWriter(System.out);
        int T = (multipleTC)?ni():1;
        //Solution Credits: Taranpreet Singh
        for(int i = 1; i<= T; i++)solve(i);
        out.flush();
        out.close();
    }
    public static void main(String[] args) throws Exception{
        if(memory)new Thread(null, new Runnable() {public void run(){try{new Main().run();}catch(Exception e){e.printStackTrace();}}}, "1", 1 << 28).start();
        else new Main().run();
    }
    long gcd(long a, long b){return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object o){out.print(o);}
    void pn(Object o){out.println(o);}
    void pni(Object o){out.println(o);out.flush();}
    String n(){return in.next();}
    String nln(){return in.nextLine();}
    int ni(){return Integer.parseInt(in.next());}
    long nl(){return Long.parseLong(in.next());}
    double nd(){return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{    
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }   
            return str;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.