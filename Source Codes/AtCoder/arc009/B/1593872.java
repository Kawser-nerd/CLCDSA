import java.util.*;

public class Main {             
    
  public static void main(String[] args) {
   
    Scanner sc = new Scanner(System.in);                                              
    
    int [] b = new int[10];
    
    for(int i = 0;i < 10;i++){
        b[sc.nextInt()] = i;
    }
    
    int N = sc.nextInt();
    
    List<Long> list = new ArrayList<>();
    
    for(int i = 0;i < N;i++){
      list.add(sc.nextLong());
    }

    Collections.sort(list,(o1,o2) -> Long.compare(f(o1,b),f(o2,b)));    
    
    for(long v:list){
        System.out.println(v);
    }
    
  }  
  
  private static long f(long x,int[] b){
      long ret = 0;
      char[] s = Long.toString(x).toCharArray();
      for(char c : s){
          ret *= 10;
          ret += b[(int) (c - '0')];
      }
      return ret;
  }    
  
}