import java.util.*;

class Main{           
    
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                                          
       
       int N = sc.nextInt();
       
       int a[] = new int[N];
       
       for(int i = 0;i < N;i++){
          a[i] = sc.nextInt();
       }
        
      TreeSet<Integer> set = new TreeSet<>();
      
      int s = 0;
      int ans = 1;
      
      set.add(a[0]);
      
      for(int t = 1;t < N;t++){
          if(set.contains(a[t])){
              while(set.contains(a[t])){
                 set.remove(a[s]);
                 s++; 
              }
              set.add(a[t]);
              ans = Math.max(ans,t-s +1);
          }else{
             set.add(a[t]);
             ans = Math.max(ans,t -s + 1);
          }                    
      }
      
      System.out.println(ans);              
       
   }
   
 }