import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int n=sc.nextInt();
			char[][] cnt=new char[n]['z'-'a'+1];
			for(int i=0;i<n;i++){
				String str=sc.next();
				for(int j=0;j<str.length();j++) cnt[i][str.charAt(j)-'a']++;
			}
			String ans="";
			for(int i=0;i<'z'-'a'+1;i++){
				int min=Integer.MAX_VALUE;
				for(int j=0;j<n;j++) min=Math.min(min, cnt[j][i]);
				char c=(char)('a'+i);
				for(int j=0;j<min;j++) ans+=Character.toString(c);
			}
			System.out.println(ans);
		}
	}
}