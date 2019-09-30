import java.util.*;
import static java.lang.Math.abs;
public class Main{
public static void main(String... args){
Scanner sc=new Scanner(System.in);
String string=sc.next();
int[] x=new int[26];
for(char c:string.toCharArray()){
x[c-'a']++;
}
for(int i=0;i<x.length;i++){
if(x[i]==0){
System.out.println((char)('a'+i));
return;
}
}
System.out.println("None");
}
}