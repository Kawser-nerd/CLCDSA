
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class R1CC {    
    static boolean[] g;
    static int[][] p;
    static int[] d;
    public static void main(String[] args){
        try{
            Scanner sc = new Scanner(new File("A-large.in"));    
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")));
            int t = sc.nextInt();
            
     X:     for(int i=0;i<t;i++){
         bw.write("Case #"+String.valueOf(i+1)+": ");
                int r = 0;
                int n = sc.nextInt();
                d = new int[n];
                p = new int[n][n];
                for(int j=0;j<n;j++){
                    d[j] = sc.nextInt();
                    for(int k=0;k<d[j];k++) p[j][k] = sc.nextInt()-1;
                }
                for(int j=0;j<n;j++){
                    g = new boolean[n];
                    if(traverse(j)){
                        bw.write("Yes");
                        bw.newLine();
                        bw.flush();
                        continue X;
                    }
                }                                                                                              
                bw.write("No");
                bw.newLine();
                bw.flush();
            }
            bw.close();
        
        } catch (Exception ex) {
            Logger.getLogger(QA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    static boolean traverse(int h){
        for(int i=0;i<d[h];i++){
            if(g[p[h][i]])return true;
            else g[p[h][i]] = true;
            if(traverse(p[h][i])) return true;
        }
        return false;
    }
}
