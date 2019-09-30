import java.util.*;
 
class Main {
  
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int L = Integer.parseInt(sc.next());
        String moji[] = new String[N];
      
      for(int i=0;i<N;i++){
        moji[i] = sc.next();
      }

      Arrays.sort(moji);
      for(int i=0;i<N;i++){
        System.out.print(moji[i]);
      }
      
    }
}