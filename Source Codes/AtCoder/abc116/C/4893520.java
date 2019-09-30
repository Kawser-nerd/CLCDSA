import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        String[] str = bf.readLine().split(" ");
        List<Integer> h = new ArrayList<>();
        for(int i = 0; i < N; i++){
            h.add(Integer.parseInt(str[i]));
        }
        System.out.println(count(h));
    }
    public static Integer min(List<Integer> data){
        Integer min = data.get(0);
        for(int i = 1; i < data.size(); i++){
            Integer value = data.get(i);
            if(value < min){
                min = value;
            }
        }
        return min;
    }
    public static int count(List<Integer> data){
        int min = min(data);
        for(int i = 0; i < data.size(); i++){
            Integer value = data.get(i);
            data.set(i, value-min);
        }
        boolean zero = true;
        List<List> a = new ArrayList<>();
        for(int i = 0; i < data.size(); i++){
            int value = data.get(i);
            if(zero && value > 0){
                a.add(new ArrayList<Integer>());
                a.get(a.size()-1).add(value);
                zero = false;
            } else if(!zero){
                if(value > 0){
                    a.get(a.size()-1).add(value);
                } else{
                    zero = true;
                }
            }
        }
        int answer = min;
        for(int i = 0; i < a.size(); i++){
            answer += count(a.get(i));
        }
        return answer;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.