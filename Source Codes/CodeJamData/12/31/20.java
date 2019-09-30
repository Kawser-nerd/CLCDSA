import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class P1 {
    
    static PrintWriter output;
    static boolean ok = true; 
    static int marcate = 0; 
    public static void main(String[] arg) throws NumberFormatException, IOException {

        BufferedReader reader = new BufferedReader(new FileReader(new File("input.txt")));
        output = new PrintWriter(new File("output.txt"));

        int cases = Integer.valueOf( reader.readLine() ); 
        for ( int c=1; c<=cases; c++ ){
            System.out.println(); 
            int n = Integer.valueOf( reader.readLine() ); 
            int [][] g = new int[n+1][n+1];
          
            boolean [] parent = new boolean[n+1]; 
            for ( int i=1; i<=n; i++ ){
                StringTokenizer tkn = new StringTokenizer( reader.readLine() ); 
                int k = Integer.valueOf( tkn.nextToken() ); 
                for ( int j=0; j<k; j++){
                    int current = Integer.valueOf( tkn.nextToken() ); 
                    g[current][i] = 1; 
                    System.out.println( i + " " + current ); 
                }
                if ( k == 0 ){
                    parent[i] = true; 
                }
            }
            ok = true; // nu are diamante
            marcate = 0; 
            for ( int i=1; i<=n; i++ ){
                if ( parent[i] ){
                    boolean [] marcat = new boolean[n+1]; 
                    marcat[i] = true;
                    marcate++;
                    go(n, i, g, marcat ); 
                }
            }
            if ( ok ){
                output.println("Case #" + c + ": No" );
            } else {
                output.println("Case #" + c + ": Yes" );
            }
            //System.out.println("Case #" + c + ": " );
        }
        output.close(); 
        
    }
    
    public static void go ( int n, int current, int [][]g, boolean [] marcat ){
        
        for ( int i=1; i<=n; i++ ){
            if ( g[current][i] == 1 && marcat[i] ){
                ok = false; 
            }
            if ( g[current][i] == 1 && !marcat[i] ){
                marcat[i] = true; 
                marcate++;
                go ( n, i, g, marcat ); 
            }
        }
    }
    /*
    public static class UnionFind{
        int [] parent; 
        int n;
        public UnionFind( int n ){
            for ( int i=1; i<=n; i++ ){
                parent[i] = i; 
            }
        }
        
        public int find( int n ){
            int ret = parent[n]; 
            if ( ret == n ){
                return ret; 
            }
        }
        
    }*/

}
