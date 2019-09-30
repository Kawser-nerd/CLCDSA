import java.util.*;
 
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    String S = sc.next();
    int[] numArray = new int[N];
    int count = 0;
    numArray[0] = 0;
    for (int i = 0; i < N-1; i++) {
        if (S.substring(i,i+1).equals("A")){
            if (i < N-1 && S.substring(i+1,i+2).equals("C")){
                count++;
            }
        }
        numArray[i+1] = count;
    }
    for (int j = 0; j < Q; j++) {
        int start = sc.nextInt();
        int end = sc.nextInt();
        int answer = numArray[end-1] - numArray[start-1];
        System.out.println(answer);
    }
  }
  
}