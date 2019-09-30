import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class P3 {
    
    static PrintWriter output;
    static Map<String,Long> dp = new HashMap(); 
    static Banda unu; 
    static Banda doi; 
    
    public static void main(String[] arg) throws NumberFormatException, IOException {

        BufferedReader reader = new BufferedReader(new FileReader(new File("input.txt")));
        output = new PrintWriter(new File("output.txt"));

        int cases = Integer.valueOf( reader.readLine() ); 
        for ( int c=1; c<=cases; c++ ){
            StringTokenizer tkn = new StringTokenizer( reader.readLine() ); 
            int n = Integer.valueOf( tkn.nextToken() ); 
            int m = Integer.valueOf( tkn.nextToken() ); 
            tkn = new StringTokenizer( reader.readLine() ); 
            unu = new Banda(n); 
            doi = new Banda(m); 
            for ( int i=0; i<n; i++ ){
                long count = Long.valueOf( tkn.nextToken() ); 
                int type = Integer.valueOf( tkn.nextToken() ); 
                unu.count[i] = count; 
                unu.totalCount += count; 
                unu.type[i] = type; 
            }
            
            tkn = new StringTokenizer( reader.readLine() ); 
            for ( int i=0; i<m; i++ ){
                long count = Long.valueOf( tkn.nextToken() ); 
                int type = Integer.valueOf( tkn.nextToken() ); 
                doi.count[i] = count; 
                doi.totalCount += count; 
                doi.type[i] = type; 
            }
            dp = new HashMap(); 
            long sol = go( unu.totalCount-1, doi.totalCount-1 ); 
            output.println( "Case #"+c+": " +sol );
        }
        output.close(); 
        
    }
    
    public static long go ( long a, long b ){
        if ( a<0 || b<0 ){
           // System.out.println( a  + " " + b );
            return 0; 
        }
        if ( dp.get(a+","+b)!=null ){
            return dp.get(a+","+b);
        }
        long t1 = unu.getTrail(a);
        long t2 = doi.getTrail(b);
        long type1 = unu.getType(a);
        long type2 = doi.getType(b); 
        long ret = 0; 
        if ( type1 == type2 ){
            long back = Math.min(t1, t2);
            ret = go( a-back, b-back) + back;
        } else {
            ret = Math.max( go(a-t1,b), go(a,b-t2) );
        }
        //System.out.println( "->"+ a + " " + b +": " + ret ); 
        dp.put(a+","+b, ret );
        return ret; 
    }
    
    public static class Banda{
        public long  totalCount=0; 
        public long [] count; 
        public long [] type; 
        public int n; 
        public Banda( int n ){
            this.n = n; 
            count = new long[n]; 
            type = new long[n]; 
        }
        
        // cate asemanatoare mai sunt?
        public long getTrail( long index ){
            long acc = 0; 
            for ( int i=0; i<n; i++ ){
                acc += count[i]; 
                if ( index < acc ){
                    acc -= count[i]; 
                    return index - acc +1; 
                }
            }
            return -1; 
        }
        
        public long getType( long index ){
            long acc = 0; 
            for ( int i=0; i<n; i++){
                acc += count[i]; 
                if ( index < acc ){
                    return type[i]; 
                }
            }
            return -1; 
        }
        
    }

}
