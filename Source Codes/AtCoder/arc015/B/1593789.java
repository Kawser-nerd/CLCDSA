import java.util.*;

public class Main {            
  public static void main(String[] args) {
   
    Scanner sc = new Scanner(System.in);                                              
                        
    int N = sc.nextInt();    
    
    double max[] = new double[N];
    double min[] = new double[N];
    
    for(int i = 0;i < N;i++){
         max[i] = Double.parseDouble(sc.next());
         min[i] = Double.parseDouble(sc.next());
    }
    
    int ans[] = new int[6];    
   
    for(int i = 0;i < N;i++){         
        
         if(max[i] >= 35){
             ans[0]++;
         }else if(max[i] >= 30){
             ans[1]++;
         }else if(max[i] >= 25){
             ans[2]++;
         }else if(max[i] < 0){
             ans[5]++;
         }
         
         
         if(min[i] >= 25){
             ans[3]++;
         }else if(min[i] < 0 && max[i] >= 0){
             ans[4]++;
         }                  
         
    }
                      
     System.out.println(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4] + " " + ans[5]);
     
  }           
}