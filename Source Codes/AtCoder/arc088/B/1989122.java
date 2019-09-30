import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int ans = 0;
        if(s.length()%2==0){
            if(s.charAt(s.length()/2-1)!=s.charAt(s.length()/2)){
                System.out.println(s.length()/2);
                return;
            }else{
                s = s.substring(0, s.length()/2) + s.substring(s.length()/2+1);
                ans =1;
            }
        }
        int center = s.length()/2;
        for(int i=1;i+center<=s.length();++i){
            if(i+center==s.length() || s.charAt(center+i)!=s.charAt(center) || s.charAt(center-i)!=s.charAt(center)){
                ans += center + i;
                break;
            }
        }
        System.out.println(ans);
    }
}