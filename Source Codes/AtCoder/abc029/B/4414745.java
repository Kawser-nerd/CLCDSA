import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int ans=0;
  for(int i=0;i<12;i++){
    String po=sc.next();
    String[]p=po.split("",0);
    for(int j=0;j<p.length;j++){
      if(p[j].equals("r")){ans++;
      break;}
    }
  }
  System.out.println(ans);
}}