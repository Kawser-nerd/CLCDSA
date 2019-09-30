import java.util.*;
import java.io.*;
public class Main{
public static void main(String [] args)throws Exception{
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = new StringTokenizer(br.readLine());
  int n = Integer.parseInt(st.nextToken());
  int x = Integer.parseInt(st.nextToken());
  int array[] = new int[n + 1];
  st = new StringTokenizer(br.readLine());
  long tot = 0;
  for(int i = 1;i <= n;i++){
  	array[i] = Integer.parseInt(st.nextToken());
  	tot += array[i];
  }
  for(int i = 2;i <= n;i++){
  	if(array[i] + array[i - 1] <= x)continue;
  	int diff = array[i] + array[i - 1] - x;
  	if(array[i] >= diff) array[i] -= diff;
  	else{
  		array[i - 1] -= (diff - array[i]);
  		array[i] = 0;
  	}
  }
  long ans = 0;
  for(int i = 1;i <= n;i++)
  	ans += array[i];
  System.out.println(tot - ans);
}
}