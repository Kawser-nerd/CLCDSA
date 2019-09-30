import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashMap<Character,Integer> map = new HashMap<>();
        map.put('O', 0);
        map.put('D', 0);
        map.put('I', 1);
        map.put('Z', 2);
        map.put('S', 5);
        map.put('B', 8);
        String str = in.next();
        for(char c :str.toCharArray()){
            System.out.print(map.containsKey(c) ? map.get(c).toString() : c);
        }
        System.out.println();
    }
}