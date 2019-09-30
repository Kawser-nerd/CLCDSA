import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String rLine = sc.nextLine();
        char[] r = rLine.toCharArray();
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('A', 4);
        map.put('B', 3);
        map.put('C', 2);
        map.put('D', 1);
        map.put('F', 0);
        double sum = 0;
        for(char c : r){
            sum += map.get(c);
        }
        System.out.println(sum/n);
    }
}