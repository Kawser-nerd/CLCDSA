import java.util.*;
 
class Main {
  
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        Integer hebi[] = new Integer[N];
		int nam = Integer.parseInt(sc.next());
        int sam = 0;
      
      for(int i=0;i<N;i++){
        hebi[i] = Integer.parseInt(sc.next());
      }
		Arrays.sort(hebi, Collections.reverseOrder());
      
      for(int i = 0;i<nam;i++){
			sam += hebi[i];
      }

		System.out.print(sam);
    }
}