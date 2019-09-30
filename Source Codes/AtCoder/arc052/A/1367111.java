import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
   String S = sc.next();
   String chk[] = S.split("");
   int cnt = 0;
   StringBuilder buf = new StringBuilder();   
   for (int i = 0; i < S.length() ; i++) {
     String chker = chk[i];
     String regex = "[0-9]+";
     Pattern p = Pattern.compile(regex);
     Matcher m = p.matcher(chker);
     if (m.find()) {
      cnt++;
      buf.append(chker);
     } else if (cnt >= 1) {
       continue;
     }
   }
   System.out.println(buf);
  }
}