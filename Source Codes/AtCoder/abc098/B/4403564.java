import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char arr[] = sc.next().toCharArray();
        int max = 0;
        for(int i = 1 ; i < arr.length - 1 ; i++){
            HashSet<Character> first = new HashSet<>();
            for(int j = i-1; j>=0 ; j-- ){
                first.add(arr[j]);
            }
            int count = 0;
            HashSet<Character> set=  new HashSet<>();
            for(int j = i ; j < arr.length ; j++ ){
                if(!set.contains(arr[j])){
                    if(first.contains(arr[j])){
                        count++;
                    }
                    set.add(arr[j]);
                }
            }
            max = Math.max(max,count);
        }
        System.out.println(max);
    }
}