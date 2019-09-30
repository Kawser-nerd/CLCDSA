import java.util.*;

public class Main {            
  private static ArrayList<Double> maxT = new ArrayList<>();
  private static ArrayList<Double> minT = new ArrayList<>();    
    
  public static void main(String[] args) {
   
    Scanner sc = new Scanner(System.in);                                              
                        
    int N = sc.nextInt();
    
    int ans[] = new int[6];
    
    for(int i = 0;i < N;i++){
         double max = sc.nextDouble();
         double min = sc.nextDouble();
         maxT.add(max);
         minT.add(min);
    }
   
    for(int i = 0;i < N;i++){         
         double max = maxT.get(i);         
        
         if(max >= 35){
             ans[0]++;
         }else if(max >= 30){
             ans[1]++;
         }else if(max >= 25){
             ans[2]++;
         }else if(max < 0){
             ans[5]++;
         }
         
         double min = minT.get(i);                 
         
         if(min >= 25){
             ans[3]++;
         }else if(min < 0 && max >= 0){
             ans[4]++;
         }                  
         
    } 
    
    for(int i = 0;i < 5;i++){
      System.out.print(ans[i] + " ");
    }
    
    System.out.println(ans[5]);
     
  }           
}