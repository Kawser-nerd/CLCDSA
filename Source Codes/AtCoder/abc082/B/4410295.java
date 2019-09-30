import java.util.*;

public class Main{
public static void main(String... args){
Scanner sc = new Scanner(System.in);
char[] a=sc.next().toCharArray();
char[] b=sc.next().toCharArray();
Arrays.sort(a);
Arrays.sort(b);
char[] c=Arrays.copyOf(b,b.length);
for(int i=b.length-1;i>=0;i--){
b[b.length-1-i]=c[i];
}
String aa=String.valueOf(a);
String bb=String.valueOf(b);
if(aa.equals(bb)){
System.out.println("No");
return;
}
String[] x=new String[]{aa,bb};
Arrays.sort(x);
if(x[0].equals(aa)){
System.out.println("Yes");
}else{
System.out.println("No");
}


}
}