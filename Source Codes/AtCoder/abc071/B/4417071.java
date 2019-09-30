import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  String s[]="abcdefghijklmnopqrstuvwxyz".split("",0);
  String po=sc.next();
  String a[]=po.split("",0);
  Map<String,Integer>map=new HashMap<>();
  for(int i=0;i<a.length;i++){
  map.put(a[i],0);
  }
  if(map.size()==26)System.out.println("None");
  else
  for(int i=0;i<s.length;i++){
  if(!map.containsKey(s[i])){
  System.out.println(s[i]);break;
  }
  }
}

}