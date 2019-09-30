import java.util.*;
 
class Main {
  
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        Integer card[] = new Integer[N];
        int Alice = 0;
        int Bob = 0;
      
      for(int i=0;i<N;i++){
        card[i] = Integer.parseInt(sc.next());
      }
		Arrays.sort(card, Collections.reverseOrder());
      
      for(int i = 0;i<N;i++){
        if(i%2==0){Alice +=card[i];}
        else{Bob +=card[i];}
      }

		System.out.print(Alice-Bob);
    }
}