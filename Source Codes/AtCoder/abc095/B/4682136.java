import java.util.*;

class Main {
    public static void main(String[] args) {
      
      Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
        int kona = Integer.parseInt(sc.next());
    	int dounatu [] = new int [N];
      
      for(int i=0;i<N;i++){
		dounatu[i] = Integer.parseInt(sc.next());
        kona = kona-dounatu[i];
      }
		Arrays.sort(dounatu);
      System.out.print(N+kona/dounatu[0]);
	    
    }
}