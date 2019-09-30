import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        //System.out.println("s = " + s + ", k = " + k);
        int ans;
        if(k > s.length()){
            ans = 0;
        }else{
            List<String> list = new ArrayList<String>();
            for(int i = 0; i <= s.length() - k; i++){
                String t = s.substring(i, i + k);
                if(!list.contains(t)){
                    list.add(t);
                }
            }
            //System.out.println(list);
            ans = list.size();
        }
        System.out.println(ans);
    }
}