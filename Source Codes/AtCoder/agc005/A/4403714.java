import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayDeque<Character> stack = new ArrayDeque<>();
        char arr[] = sc.next().toCharArray();
        for(int i = 0 ; i < arr.length ; i++){
            if(arr[i] == 'S'){
                stack.push('S');
            } else {
                if(!stack.isEmpty() && stack.peek() == 'S'){
                    stack.pop();
                } else {
                    stack.push('T');
                }
            }
        }
        System.out.println(stack.size());
    }
}