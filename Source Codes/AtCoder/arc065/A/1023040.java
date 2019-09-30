import java.util.*;
import java.io.*;
public class Main{
	static boolean match(String temp,int start,String str){
		if(start + temp.length() > str.length())return false;
		//System.out.println(temp + " " + start + " " + str);
		for(int j =  0;j < temp.length();j++){
			//if(start == 5)System.out.println(temp.charAt(j) + " " + str.charAt(j + start));
			if(temp.charAt(j) != str.charAt(j + start))return false;
		}
		return true;
	}
	public static void main(String[] args) throws Exception{
            String array[] = new String[]{"dreamer","dream","eraser","erase"};
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str = br.readLine();
            int start = 0;
            int last = -1;
            while(start < str.length() && start >= 0){
            	boolean flag = false;
				for(int j = 0;j < 4;j++){
        			if(match(array[j],start,str)){
        				start += array[j].length();
        				flag = true;
        				last = j;
        				break;
        			}
        		}
        		if(!flag && last == 0){
        			start -= 2;
        			last = -1;
        		}
        		else if(!flag)break;
        		//System.out.println(start + " " + str.length());
            }
            if(start == str.length())System.out.println("YES");
            else System.out.println("NO");
	}
}