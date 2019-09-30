import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        LinkedList<Character> res = new LinkedList<>();
        int right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') right++;
            else{
                if(right>0) right--;
                else{
                    res.add(')');
                }
            }
            res.addFirst(s[i]);
        }
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<right;i++) ans.append('(');
        while(res.size()>0) ans.append(res.poll());
        System.out.println(ans.toString());
    }
}