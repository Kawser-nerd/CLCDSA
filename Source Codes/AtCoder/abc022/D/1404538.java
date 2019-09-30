import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N=Integer.parseInt(scan.next());
        int P[][][]=new int[2][2][N];
        long sum[][]=new long[2][2];
        for(int j=0;j<2;j++){
        for(int i=0;i<N;i++){
            P[j][0][i]=Integer.parseInt(scan.next());
            P[j][1][i]=Integer.parseInt(scan.next());
            sum[j][0]+=0L+P[j][0][i];
            sum[j][1]+=0L+P[j][1][i];
        }
        }
        
        BigDecimal[][] w = new BigDecimal[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                w[i][j] =BigDecimal.valueOf(sum[i][j]);
                w[i][j]=w[i][j].divide(BigDecimal.valueOf(N),10,RoundingMode.HALF_UP);
            }
        }
        
        BigDecimal[] maxdis = new BigDecimal[2];
        maxdis[0]=BigDecimal.valueOf(0);
        maxdis[1]=BigDecimal.valueOf(0);
        
            for(int i=0;i<N;i++){
                BigDecimal[] dis=new BigDecimal[2];
                for(int j=0;j<2;j++){
                    BigDecimal px=BigDecimal.valueOf(P[j][0][i]);
                    px=px.subtract(w[j][0]);
                    px=px.multiply(px);
                    BigDecimal py=BigDecimal.valueOf(P[j][1][i]);
                    py=py.subtract(w[j][1]);
                    py=py.multiply(py);
                    dis[j] = px.add(py);
                    if(maxdis[j].compareTo(dis[j])<0){
                        maxdis[j]=dis[j];
                    }
                }
        }
        
        BigDecimal P_=maxdis[1].divide(maxdis[0],8,RoundingMode.HALF_UP);
        
        
        System.out.println(Math.sqrt(P_.doubleValue()));
        
        
    }
    
    
    
}