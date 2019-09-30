import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        String w = sc.next();
        //?????????????????
        int[] alphabet = new int[26];

        for(int i = 0; i < w.length(); i++){
            //char?(??????)????????????
            alphabet[w.charAt(i) - 'a']++;
        }
        
        //???????????????????
        boolean beauty = true;
        for(int i = 0; i < 26; i++){
            if(alphabet[i] % 2 != 0)beauty = false;
        }
        
        //????????
        System.out.println(beauty? "Yes" : "No");
    }
}