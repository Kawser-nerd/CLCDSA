import java.util.*;

public class Main{       
    
    private static int cost(int a[],int c1 ,int c2){
       int sum = 0;
      
       for(int i = 0;i < a.length;i+=2){
           if(a[i] != c1){
               sum++;
           }
       }   
       
       for(int j = 1;j < a.length;j+=2){
           if(a[j] != c2){
               sum++;
           }           
       }
       
       return sum;        
    }    
    
    public static void main(String[] args){            
       
        Scanner sc = new Scanner(System.in);        
                      
         int n = sc.nextInt();
         
         int c = sc.nextInt();
         
         int a[] = new int[n];
         
         for(int i = 0;i < n;i++){
             a[i] = sc.nextInt();
         }                 
         
         int ans = Integer.MAX_VALUE;
         
         for(int i = 1 ;i <=10;i++){
             for(int j = 1;j <= 10;j++){
                 if(i == j){
                     continue;
                 }                 
                 ans = Math.min(ans,cost(a,i,j)*c);
             }             
         }
  
         System.out.println(ans);
        
         
    }                               
}