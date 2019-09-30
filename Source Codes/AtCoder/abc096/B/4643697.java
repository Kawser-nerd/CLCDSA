import java.util.*;

class Main {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = Integer.parseInt(sc.next());
      	int B = Integer.parseInt(sc.next());
      	int C = Integer.parseInt(sc.next());
      	int K = Integer.parseInt(sc.next());
        int[]hako = {A,B,C};
      
      	Arrays.sort(hako);
      int max = hako[2];
      	for(int i=0;i<K;i++){
          max = max *2;
        }
      max = max + hako[0] + hako[1];
      System.out.print(max);
      
      
      
    }
}