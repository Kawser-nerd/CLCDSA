import java.util.*;

public class Main{      
    
    public static void main(String[] args){
      
       Scanner sc = new Scanner(System.in);
     
       int l = sc.nextInt();
       int r = sc.nextInt();
       
       int ls[] = new int[41];
       int rs[] = new int[41];
       
       for(int i = 0;i < l;i++)
          ls[sc.nextInt()]++;
       
       for(int i = 0;i < r;i++)
          rs[sc.nextInt()]++;
       
       int sum = 0;
       
       for(int i = 0;i < 41;i++){
           sum += Math.min(ls[i],rs[i]);           
       }
       
       System.out.println(sum);
              
    }        
}