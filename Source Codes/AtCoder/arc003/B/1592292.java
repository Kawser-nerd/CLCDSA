import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);                                              
                        
     int N = sc.nextInt();
     
     String a[] = new String[N];
     
     for(int i = 0;i < N;i++){
         String temp = sc.next();
         StringBuffer sb = new StringBuffer(temp);
         a[i] = sb.reverse().toString();
     }
     
     Arrays.sort(a);
     
     for(int i = 0;i < N;i++){
         StringBuffer sb = new StringBuffer(a[i]);         
         System.out.println(sb.reverse().toString());
     }
     
  }           
}