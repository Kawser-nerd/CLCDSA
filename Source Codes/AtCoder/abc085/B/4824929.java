import java.util.*;
 
class Main {
  
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        Integer moti[] = new Integer[N];
        int co = 1;
      
      for(int i=0;i<N;i++){
        moti[i] = Integer.parseInt(sc.next());
      }
		Arrays.sort(moti, Collections.reverseOrder());
      
      for(int i= 1;i<N;i++){
        if(moti[i-1]>moti[i]){co++;}
      }

		System.out.print(co);
    }
}