import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    String s = sc.nextLine();
    double sum = 0.0;
    for(int i = 0; i < N; i++){
      switch(s.charAt(i)){
        case 'A' :
          sum += 4.0;
          break;
        case 'B' :
          sum += 3.0;
          break;
        case 'C' :
          sum += 2.0;
          break;
        case 'D' :
          sum += 1.0;
          break;
      }
    }
    System.out.println(sum / N);
  }
}