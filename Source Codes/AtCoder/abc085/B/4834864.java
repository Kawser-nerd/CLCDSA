import java.util.*;
 
class Main {
  
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
       Set<String> set = new HashSet();
      
      for(int i=0;i<N;i++){
        set.add(sc.next());
      }
      System.out.println(set.size());
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.