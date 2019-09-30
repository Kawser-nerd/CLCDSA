import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Map<Character, Integer> map = new HashMap<>();
    char[] chars = {'M', 'A', 'R', 'C', 'H'};
    for(int i = 0; i < chars.length; i++){
      map.put(chars[i], 0);
    }
    for(int i = 0; i < n; i++){
      switch(sc.next().charAt(0)){
        case 'M':
          map.put('M', map.get('M')+1);
          break;
        case 'A':
          map.put('A', map.get('A')+1);
          break;
        case 'R':
          map.put('R', map.get('R')+1);
          break;
        case 'C':
          map.put('C', map.get('C')+1);
          break;
        case 'H':
          map.put('H', map.get('H')+1);
          break;
        default:
          break;
      }
    }
    long sum = 0;
    for(int i = 0; i <= 2; i++){
      for(int j = i + 1; j <= 3; j++){
        for(int k = j + 1; k <= 4; k++){
          sum += (long)map.get(chars[i]) * map.get(chars[j]) * map.get(chars[k]);
        }
      }
    }
    System.out.println(sum);
  }
}