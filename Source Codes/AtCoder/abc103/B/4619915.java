import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean boo = false;
        String s = sc.next();
        String t = sc.next();
        String str[] = t.split("");
        List<String> list = Arrays.asList(str);
        List<String> list2 = new ArrayList<>(list);
        for(int i=0; i<s.length(); i++){
            String ans = "";
            for(int j=0; j<list2.size(); j++){
                ans += list2.get(j);
            }
            if(ans.equals(s)){
                boo = true;
                break;
            }
            list2.add(list2.get(0));
            list2.remove(0);
        }
        if(boo) System.out.println("Yes");
        else System.out.println("No");
    }
}