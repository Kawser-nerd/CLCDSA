import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    int N = 2025 - n;
    
    List<String> list = new ArrayList<>();
    for(int i = 1; i <= 9; i++){
      for(int j = i; j <= 9; j++){
        if(i * j == N && i == j){
          list.add(new String(i + " x " + j));
        }else if(i * j == N){
          list.add(new String(i + " x " + j));
          list.add(new String(j + " x " + i));
        }
      }
    }
    Collections.sort(list);
    for(String s : list){
      System.out.println(s);
    }
  }
}