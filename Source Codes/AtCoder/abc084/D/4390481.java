import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] l = new int[n];
    int[] r = new int[n];
    int max = 0;
    for(int i =0; i < n; i++){
      l[i] = sc.nextInt();
      r[i] = sc.nextInt();
      max = max > r[i] ? max : r[i];
    }
    List<Integer> list = likeMake(sosuMake(max));
    for(int i = 0; i < n; i++){
      Integer lt = l[i];
      Integer rt = r[i];
      int low = Collections.binarySearch(list, lt);
      int high = Collections.binarySearch(list, rt);
      if(low < 0){
        low = ~low;
      }
      if(high < 0){
        high = ~high;
      }else{
        high++;
      }
      System.out.println(high - low);
    }
  }
  
  public static List<Integer> sosuMake(int max){
    List<Integer> list = new ArrayList<>();
    list.add(2);
    for(int i = 3; i <= max; i += 2){
      for(int j = 0; j < list.size(); j++){
        int tmp = list.get(j);
        if(tmp * tmp > i){
          list.add(i);
          break;
        }else if(i % tmp == 0){
          break;
        }
      }
    }
    return list;
  }
  
  public static List<Integer> likeMake(List<Integer> sosu){
    List<Integer> list = new ArrayList<>();
    for(int num : sosu){
      if(num == 2) continue;
      Integer tmp = (num + 1) / 2;
      if(Collections.binarySearch(sosu, tmp) >= 0){
        list.add(num);
      }
    }
    return list;
  }
}