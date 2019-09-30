import java.util.*;
public class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    sc.nextLine();
    Map<String,Integer>map=new HashMap<String,Integer>();
    for(int i=0;i<n;i++){
      String po=sc.nextLine();
    if(map.get(po)==null)map.put(po,1);
      else map.put(po,map.get(po)+1);
    }
    String p="";int a=0;
    for(String key:map.keySet()){
        if(map.get(key)>a){a=map.get(key);
        p=key;}
        
    }
    System.out.println(p);
  }
}