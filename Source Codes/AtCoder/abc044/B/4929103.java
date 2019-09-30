import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] chars={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        String str=sc.next();
        for(int i=0;i<26;i++){
            if((str.length()-str.replaceAll(chars[i],"").length())%2==1){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");

    }
    
 
}