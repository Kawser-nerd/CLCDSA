import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        ArrayList<Integer>[] dic = new ArrayList[26];
        for(int i=0;i<26;i++) dic[i]=new ArrayList<>();
        for(int i=0;i<s.length();i++){
            char cur = s.charAt(i);
            dic[cur-'a'].add(i);
        }
        int ans = 100;
        for(int i=0;i<26;i++){
            if(dic[i].size()==0) continue;
            int temp = dic[i].get(0);
            for(int j=0;j<dic[i].size()-1;j++){
                temp = Math.max(temp,dic[i].get(j+1)-dic[i].get(j)-1);
            }
            temp = Math.max(temp,s.length()-1-dic[i].get(dic[i].size()-1));
            ans = Math.min(ans,temp);
        }
        System.out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.