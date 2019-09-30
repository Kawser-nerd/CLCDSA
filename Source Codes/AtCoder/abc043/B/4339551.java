import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int num = s.length();
        List<String> list = new ArrayList<>();
        
        for(int i = 0; i < num; i++){
            //??????????????
            if(list.size() == 0 && s.charAt(i) == 'B')continue;
            
            //0,1??????????B??????
            if(s.charAt(i) == '0')list.add("0");
            if(s.charAt(i) == '1')list.add("1");
            if(s.charAt(i) == 'B')list.remove(list.size() -1);
        }
        
        for(int i = 0; i < list.size(); i++)System.out.print(list.get(i));
    }
}