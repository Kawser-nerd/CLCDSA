import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().split(" ");
    int N = Integer.parseInt(s[0]);
    int M = Integer.parseInt(s[1]);
    
    List<Integer> list1 = new ArrayList<>();
    
    for(int i = 0; i< N; i++){
      list1.add(sc.nextInt());
    }
    
    Collections.sort(list1, Collections.reverseOrder());
    
    List<Integer> list2 = new ArrayList<>();
    
    for(int i = 0; i < M; i++){
      list2.add(list1.get(i));
    }
    
    Collections.sort(list2);
    
    double rate = 0.0;
    for(int i = 0; i < M; i++){
      rate = (rate + list2.get(i)) / 2;
    }
    System.out.println(rate);
  }
}