import java.util.*;

public class Main { 
    
	public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            
            double N  = sc.nextDouble();
            double va = sc.nextDouble();
            double vb = sc.nextDouble();
            double L  = sc.nextDouble();            

        double y = L;
        for(int i = 0 ;i < N;i++){  
            double x = y/va;
            
            y = vb*x;                        
        }
                                                    
            System.out.println(y);    
                    
        }             
}