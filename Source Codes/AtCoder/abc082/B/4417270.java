import java.util.*;
public class Main{
public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  String po=sc.nextLine();
  char[]c=po.toCharArray();
  Arrays.sort(c);
  po="";
  for(int i=0;i<c.length;i++){
      po+=c[i];
  }
  
  String po2=sc.nextLine();
  char[]c2=po2.toCharArray();
  Arrays.sort(c2);
  po2="";
  for(int i=0;i<c2.length;i++){
      po2+=c2[c2.length-1-i];
  }
  System.out.println((po.compareTo(po2)<0)?"Yes":"No");
}

}