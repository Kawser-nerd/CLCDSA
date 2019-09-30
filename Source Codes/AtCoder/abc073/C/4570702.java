import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  Map<Integer,Boolean>map=new HashMap<>();
  for(int i=0;i<n;i++){
  int a=sc.nextInt();
    if(map.containsKey(a)){map.put(a,!map.get(a));}else map.put(a,true); 
  }
  int ans=0;
  for(Integer key:map.keySet())ans+=map.get(key)?1:0;
  System.out.println(ans);
}
}