import java.util.*;

class Main {
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int[] input = new int[3];
    int fiveCount = 0;
    int sevenCount = 0;

    for(int i = 0; i < 3; i++){
      input[i] = sc.nextInt();
      if(input[i] == 5 && fiveCount < 2){
        fiveCount++;
      }else if(input[i] == 7 && sevenCount < 1){
        sevenCount++;
      }else {
        System.out.println("NO");
        return;
      }
    }
    System.out.println("YES");
  }
}