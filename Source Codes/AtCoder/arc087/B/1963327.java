import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

class Main{

    static boolean canSet(int x,List<Integer> list){
        Set<Integer> set = new HashSet<>();
        set.add(0);
        for(int i : list){
            Set<Integer> newSet = new HashSet<>();
            for(int j : set){
                newSet.add(j+i);
                newSet.add(j-i);
            }
            set = newSet;
        }
        return set.contains(x);
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        String s = scan.next() + 'T';
        int x = scan.nextInt();
        int y = scan.nextInt();
        
        List<Integer> hol = new ArrayList<>();
        List<Integer> ver = new ArrayList<>();
        int index = 0;
        while(s.charAt(index)!='T')++index;
        x -= index;

        int cnt=0;
        int vec=0;
        for(int i=index;i<s.length();++i){
            if(s.charAt(i)=='F')++cnt;
            else{
                ++vec;
                if(cnt>0){
                    if(vec%2==1)hol.add(cnt);
                    else ver.add(cnt);
                    cnt=0;
                }
            }
        }

        if(canSet(x, hol) && canSet(y, ver)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}