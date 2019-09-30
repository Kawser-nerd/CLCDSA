import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String array[] = str.split("");
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0; i<array.length; i++){
            list.add(Integer.parseInt(array[i]));
        }
        int min = 1000;
        for(int i=2; i<list.size(); i++){
            int sum = 0;
            sum += list.get(i-2) * 100;
            sum += list.get(i-1) * 10;
            sum += list.get(i);
            if(Math.abs(sum-753) < min) min = Math.abs(sum-753);
        }
        System.out.println(min);
    }
}