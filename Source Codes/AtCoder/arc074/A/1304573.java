import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
    Scanner cin = new Scanner(System.in);
    
    int H = cin.nextInt();
    int W = cin.nextInt();
    cin.close();
    long result = 0L;    
    if(W==H){
        result = calcMin(H,W);
    }else{
        result = Math.min(calcMin(H,W),calcMin(W,H));
    }
    System.out.println(result);
    }
    
    public static long calcMin(int H,int W){
        long S1 = 0L;
        long S2 = 0L;
        long S3 = 0L;
        long S4 = 0L;
        long S5 = 0L;
        long Smin = Long.MAX_VALUE;
        long tmpS;
        for(long i=1;i<H;i++){
            S1 = i*W;
            S2 = (H-i)*(W/2);
            S3 = (H-i)*(W-(W/2));
            tmpS = Math.max(Math.max(S1,S2),S3) - Math.min(Math.min(S1,S2),S3); 
            if(tmpS<Smin){
                Smin = tmpS;
            }
            if(i<=H-2){
                S4 = W*((H-i)/2);
                S5 = W*(H-i-((H-i)/2));
                tmpS = Math.max(Math.max(S1,S4),S5) - Math.min(Math.min(S1,S4),S5);
                if(tmpS<Smin){
                    Smin = tmpS;
                }
            }
        }
        return Smin;
    }
}