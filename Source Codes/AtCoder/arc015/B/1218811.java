import java.util.*;

public class Main {
	public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                        
                int N = sc.nextInt();                
                
                double min[] = new double[N];
                double max[] = new double[N];
                
                for(int i = 0 ;i < N;i++){
                    max[i] = Double.parseDouble(sc.next());                                                                 
                    min[i] = Double.parseDouble(sc.next());                    
                }
                
                int a[] = new int[6];
                
                for(int i = 0 ;i < N;i++){                    
                    if(max[i] >= 35){
                        a[0]++;
                    }else if(max[i] >= 30){
                        a[1]++;
                    }else if(max[i] >= 25){
                        a[2]++;
                    }else if(max[i] < 0){
                        a[5]++;                           
                    }
                    if(min[i] >= 25){
                        a[3]++;
                    }                    
                    if(min[i] < 0 && max[i]>= 0){
                        a[4]++;
                    }
                }
                
                System.out.println(a[0] + " " + a[1] + " " + a[2] + " " + a[3] + " " + a[4] + " " + a[5]);                              
        }       
}