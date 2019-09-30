import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> list = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String li0 = "";
        for(int i = 0; i < w; i++){
            li0 += "#";
        }
        list.add(li0);
        
        for(int i = 0; i < h; i++){
            String s = sc.next();
            list.add(s);
        }
        list.add(li0);

        for(int i = 0; i < list.size(); i++){
            System.out.println("#" + list.get(i) + "#");
        }
    }    
}