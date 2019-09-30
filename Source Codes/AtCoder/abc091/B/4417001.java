import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  Map<String,Integer>map=new HashMap<String,Integer>();
  int n=sc.nextInt();
  for(int i=0;i<n;i++){
  	String po=sc.next();
    map.put(po,(map.containsKey(po))?map.get(po)+1:1);
  }
  int m=sc.nextInt();
  for(int i=0;i<m;i++){
  	String po=sc.next();
    map.put(po,(map.containsKey(po))?map.get(po)-1:-1);
  }
  int ans=0;
  for(String key:map.keySet()){
      
      ans=Math.max(ans,map.get(key));
  }
  System.out.println(ans);
  

}

}