import java.util.*;

class Main{           
 
   public static void main(String[] args){
      
      Scanner sc = new Scanner(System.in);
    
      int l[] = new int[41];
      int r[] = new int[41];
      
      int L = sc.nextInt();
      int R = sc.nextInt();
      
      for(int i = 0;i < L;i++){
          l[sc.nextInt()]++; 
      }
      
      for(int i = 0;i < R;i++){
          r[sc.nextInt()]++;
      }
      
      int ans = 0;
      for(int i = 10;i <=40;i++){
          ans += Math.min(l[i],r[i]);
      }
      System.out.println(ans);
      
   }   
 }