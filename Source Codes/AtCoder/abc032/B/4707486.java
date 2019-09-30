import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        int k=sc.nextInt();
        if(s.length()<k){
            System.out.println(0);
            return;
        }
        String[] words=new String[s.length()-k+1];
        for(int i=0;i<words.length;i++){
            words[i]=s.substring(i,i+k);
        }
        Arrays.sort(words);
        int output=words.length;
        for(int i=1;i<words.length;i++){
            if(words[i-1].equals(words[i]))output--;
        }
        System.out.println(output);
    }
        

    
}