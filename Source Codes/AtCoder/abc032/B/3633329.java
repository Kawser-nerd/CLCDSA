import java.util.*;
import static java.lang.System.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(in);
HashSet<String> set=new HashSet<>();
String s=sc.next();
int k = Integer.parseInt(sc.next());
    for (int i = 0; i <= s.length()-k; i++) {
        String p=s.substring(i,i+k);
        set.add(p);
    }
    out.println(set.size());
}}