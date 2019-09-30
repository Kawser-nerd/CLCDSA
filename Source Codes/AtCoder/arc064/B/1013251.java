import java.util.*;
import java.io.*;
public class Main{
public static void main(String [] args)throws Exception{
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  String str = br.readLine();
  int cnt[] = new int[26];
  for(int i = 0;i < str.length();i++){
  	cnt[str.charAt(i) - 'a']++;
  }
  int diff = 0;
  for(int i = 0;i < cnt.length;i++){
  	if(cnt[i] > 0)++diff;
  }
  if(diff == 2){
  	System.out.println("Second");
  }
  else{
  	if(str.charAt(0) == str.charAt(str.length() - 1)){
  		String str1 = ((str.length() - 3) & 1) == 0 ? "Second" : "First";
  		System.out.println(str1);
  	}
  	else{
  		String str1 = ((str.length() - 2) & 1) == 0 ? "Second" : "First";
  	    System.out.println(str1);
  	}
  }
}
}