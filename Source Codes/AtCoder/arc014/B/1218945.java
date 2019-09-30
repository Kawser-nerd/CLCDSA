import java.util.*;

public class Main {
	public static void main(String[] args) {
              Scanner sc = new Scanner(System.in);
                        
              int N = sc.nextInt();                
              
              HashSet<String> used = new HashSet<>();
              
              String a[] = new String[N];
              for(int i = 0 ;i < N;i++){
                  a[i] = sc.next();
              }              
              
              String prev = a[0];           
              used.add(prev);
              for(int i = 1 ;i < N;i++){                                    
                  String current = a[i];                  
                  if(prev.charAt(prev.length() - 1) != current.charAt(0) || used.contains(current)){
                             System.out.println(i%2 == 0 ?"LOSE":"WIN");
                             return;
                  }
                  used.add(current);
                  prev = current;
              }                                
               
              System.out.println("DRAW");                
                
        }       
}