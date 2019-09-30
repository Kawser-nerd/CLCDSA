package round_1B_2010;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Scanner;

public class LoadTesting {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<Character, String> map=new HashMap<Character, String>();
		map.put('0', "0000");
		map.put('1', "0001");
		map.put('2', "0010");
		map.put('3', "0011");
		map.put('4', "0100");
		map.put('5', "0101");
		map.put('6', "0110");
		map.put('7', "0111");
		map.put('8', "1000");
		map.put('9', "1001");
		map.put('A', "1010");
		map.put('B', "1011");
		map.put('C', "1100");
		map.put('D', "1101");
		map.put('E', "1110");
		map.put('F', "1111");
		
		Scanner reader=new Scanner(System.in);
		try {
			FileWriter writer=new FileWriter(new File("D:/ltout1.txt"));
			int t=reader.nextInt();
			for(int cc=1;cc<=t;++cc){
				int m=reader.nextInt();
				int n=reader.nextInt();
				boolean chees[][]=new boolean[m][n];
				for(int i=0;i<m;++i){
					String line=reader.next();
					for(int j=0;j<n/4;++j){
						char c=line.charAt(j);
						String temp=map.get(c);
						for(int k=0;k<4;++k){
							if(temp.charAt(k)=='0'){
								chees[i][j*4+k]=false;
							}
							else{
								chees[i][j*4+k]=true;
							}
							
						}
					}
				}
				
				boolean flag[][]=new boolean[m][n];
				int result[]=new int[512];
				int k=Math.min(m-1, n-1);
				for(;k>=0;--k){
					for(int i=0;i<m;++i){
						if((i+k)>=m){
							break;
						}
						for(int j=0;j<n;++j){
							if((j+k)>=n){
								break;
							}
							if(flag[i][j]){		
								continue;
							}
							
							boolean ff=true;
							for(int p=i;p<=i+k;++p){
								for(int q=j;q<=j+k;++q){
									if(flag[p][q]){
										p=i+k+1;
										ff=false;
										break;
									}
									int sub=p-i+q-j;
									
									if(sub%2==0&&chees[i][j]==chees[p][q]){
										continue;
									}
									else if(sub%2==1&&chees[i][j]!=chees[p][q]){
										continue;
									}
									else{
										ff=false;
										p=i+k+1;
										break;
									}
								
								}
							}
							
							if(ff){
								for(int p=i;p<=i+k;++p){
									for(int q=j;q<=j+k;++q){
										flag[p][q]=true;
									}
								}
								;
								result[k+1]++;
							}
						}
					}
				}
				int sum=0;
				int total=0;
				StringBuffer out=new StringBuffer();
				for(int i=result.length-1;i>=1;--i){
					if(result[i]!=0){
						sum++;
						total+=(result[i]*i*i);
						out.append(i+" "+result[i]+"\r\n");
					}
					else{
						
					}
						
				}
//				sum++;
//				total=n*m-total;
//				if(total>0)
//					out.append("1 "+total+"\r\n");
				writer.write("Case #"+cc+": "+sum+"\r\n");
				writer.write(out.toString());
				writer.flush();
			}
			writer.close();
			
			
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}
