import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s = sc.next().substring(0,12);
        char[] key="WBWBWWBWBWBW".toCharArray();
        String[] d=new String[7];
        for (int i = 0; i < d.length; i++) {
            d[i]="";
        }
        int c=0;
        for (int i = 0; i < 12; i++) {
            if(key[i]=='W'){
                for (int j = i; j < i+12; j++) {
                    d[c]=d[c]+Character.toString(key[j%12]);
                }
                c++;
            }
        }
        String[] ans={"Do","Re","Mi","Fa","So","La","Si"};
        for (int i = 0; i < 7; i++) {
            if(d[i].equals(s)){
                out.println(ans[i]);
                break;
            }
        }
    }
}