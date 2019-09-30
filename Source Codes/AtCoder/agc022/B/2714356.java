import java.util.*;
import java.io.*;
import java.math.*;
 
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{ 
 
 
    static long mod=1000000007;
    // static int dx[]={1,-1,0,0};
    // static int dy[]={0,0,1,-1};
    // // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    // HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    // ArrayList<Integer> lis = new ArrayList<Integer>();
    // ArrayList<Integer> map[]=new ArrayList[26];
    // static HashMap<Integer,Long> map = new HashMap<Integer,Long>();

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}
        
        int n = sc.nextInt();
        int a[] = new int[20000];
        for(int i=1; i<=15000; i++) {
            a[i-1] = i*2;
        }
        for(int i=3,t=15001; t<=20000; i+=6,t++) {
            a[t-1] = i;
        }
        if(n<15000){
            if(n==3){a[0]=2;a[1]=5;a[2]=63;}
            else if(n%3==1){
                a[2]=3;a[3]=9;
            }
            else{
                a[1]=3;a[3]=9;
            }
        }
        if(n>15000 && n%2==1)a[2]=0;


        for(int i=0; i<n; i++) {
            if(a[i]>0)
                out.print(a[i]+" ");
            else n++;
        }

        out.println();
        out.flush();
    }

    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }
     
    static boolean validpos(int x,int y,int r, int c){
        return x<r && 0<=x && y<c && 0<=y;
    }
     
    static boolean bit(long x,int k){
        // weather k-th bit (from right) be one or zero
        return  ( 0 < ( (x>>k) & 1 )  )  ? true:false;
    }    
}

class Cake implements Comparable<Cake>{
    int id;
    long x;
    Cake(int id, long x) {
        this.id=id;
        this.x=x;
    } 
      
    public int compareTo(Cake p){
        return (- x + p.x)>=0 ? 1:-1;//des
    } 
}


class P implements Comparable<P>{
    int x,y;
    P(int x, int y) {
        this.x=x;
        this.y=y;
    } 
      
    public int compareTo(P p){
        return -x + p.x;//des
    } 
}

class Reader
{ 
    private BufferedReader x;
    private StringTokenizer st;
    
    public Reader(InputStream in)
    {
        x = new BufferedReader(new InputStreamReader(in));
        st = null;
    }
    public String nextString() throws IOException
    {
        while( st==null || !st.hasMoreTokens() )
            st = new StringTokenizer(x.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    public long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }
}