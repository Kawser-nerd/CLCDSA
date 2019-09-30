import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int time = sc.nextInt();
        String n = Integer.toString(time);
        String str[] = n.split("");
        String s = str[0];
        for(int i=1; i<str.length; i++){
            str[i] = str[0];
            s += str[i];
        }
        int x = Integer.parseInt(s);
        if(x >= time) System.out.println(x);
        else{
            int a = Integer.parseInt(str[0]) +1;
            for(int i=0; i<str.length; i++){
                System.out.print(a);
            }
        }
    }
}