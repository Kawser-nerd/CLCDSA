import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    String s = sc.nextLine();
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for(int i = 0; i < N; i++){
      switch(s.charAt(i)){
        case '1':
          a++;
          break;
        case '2':
          b++;
          break;
        case '3':
          c++;
          break;
      }
    }
    d = N - a - b - c;
    int max = 0;
    int min = N;
    
    if(a >= b){
      if(a > max){
        max = a;
      }
      if(b < min){
      min = b;
      }
    }else{
      if(b > max){
        max = b;
      }
      if(a < min){
      min = a;
      }
    }
    
    if(c >= d){
      if(c > max){
        max = c;
      }
      if(d < min){
      min = d;
      }
    }else{
      if(d > max){
        max = d;
      }
      if(c < min){
      min = c;
      }
    }
    System.out.println(max + " " + min);
  }
}