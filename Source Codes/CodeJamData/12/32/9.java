
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class R1CB {    
    public static void main(String[] args){
        try{
            Scanner sc = new Scanner(new File("B-large.in"));    
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")));
            int t = sc.nextInt();            
            for(int i=0;i<t;i++){
                bw.write("Case #"+String.valueOf(i+1)+": ");
                bw.newLine();
                double d = sc.nextDouble();
                int n = sc.nextInt();
                int acc = sc.nextInt();
                double[] times = new double[n];
                double[] dist = new double[n];
                for(int j=0;j<n;j++){
                    times[j] = sc.nextDouble();
                    dist[j] = sc.nextDouble();
                }
                for(int j=0;j<acc;j++){
                    double a = sc.nextDouble();
                    double k = 0;                   
                    for(int q=0;q<n;q++){
                        double t1 = times[q];
                        double x = dist[q];
                        if(x>d){
                            double t4 = 0;
                            double d4 = 0;
                            if(q>0){
                                t4 = times[q-1];
                                d4 = dist[q-1];
                            }
                            t1 = t4+(times[q]-t4)*(d-d4)/(dist[q]-d4);
                            q=n;
                            x = d;
                        }                       
                        double k1 = t1 - Math.sqrt(2*x/a);
                        if(k1>k) k = k1;
                    }
                    k += Math.sqrt(2*d/a);
                    bw.write(String.valueOf(k));
                    bw.newLine();
                    bw.flush();
                }                
            }
            bw.close();
        
        } catch (Exception ex) {
            Logger.getLogger(QA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
