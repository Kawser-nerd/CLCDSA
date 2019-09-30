import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        String[] S ={ sc.next(), sc.next(), sc.next()};
        
        int i = 0;
        while(S[i].length() != 0){
                int turn = S[i].charAt(0) - 'a';   //?????????ASCII?????????
                S[i] = S[i].substring(1);          //????????
                i = turn;
        }
        
        //char????????ASCII??????????
        System.out.println((char)('A' + i));
    }
}