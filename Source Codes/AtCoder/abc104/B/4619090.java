import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String str[] = s.split("");
        boolean boo = true;
        if(!str[0].equals("A")) boo = false;
        int count = 0;
        int index = 0;
        for(int i=2; i<str.length-1; i++){
            if(str[i].equals("C")){
                count++;
                index = i;
            }
        }
        if(count != 1) boo = false;
        for(int i=1; i<str.length; i++){
            if(i == index) continue;
            if(Character.isUpperCase(s.charAt(i))){
                boo = false;
            }
        }
        if(boo) System.out.println("AC");
        else System.out.println("WA");
    }
}