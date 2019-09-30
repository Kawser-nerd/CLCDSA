import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
      
     Scanner sc = new Scanner(System.in);
	 	int N = sc.nextInt();
              
      	int sum = 0; //??
      	String name[] = new String[N]; //??
        int people[] = new int[N]; //??	
            
      for(int i = 0; i < N; i++) {
        name[i] = sc.next();
        people[i] = sc.nextInt();
        sum += people[i];
      }
      sc.close();      

      String answer = "atcoder";
      for(int i = 0; i < N; i++) {      
      if( sum / 2 < people[i]){
        answer = name[i];
      }
    }
      System.out.println(answer);
  }
}