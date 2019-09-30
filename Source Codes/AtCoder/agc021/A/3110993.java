import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(in);
String s=sc.next();
int ans;
int c=0;
for(int j=1;j<s.length();j++){
if(s.charAt(j)=='9')c++;
}
if(c==s.length()-1){
    ans=9*(s.length()-1)+Character.getNumericValue(s.charAt(0));
}else{
    ans=Character.getNumericValue(s.charAt(0))+9*(s.length()-1)-1;
}
    out.println(ans);
}}