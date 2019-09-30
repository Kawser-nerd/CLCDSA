import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		
		char[] a=new char[n], b=new char[n];
		for(int i=0;i<n;i++){
			a[i]=s.charAt(i);
			b[i]=s.charAt(2*n-1-i);
		}
		HashMap<String,Long> am=get(a),bm=get(b);
		Set<String> keyset=am.keySet();
		long res=0;
		for(String str: keyset){
			try{
				long aa=am.get(str), bb=bm.get(str);
				res+=aa*bb;
			}catch(Exception e){}
		}
		System.out.println(res);
	}
	static HashMap<String,Long> get(char[] a){
		int n=a.length;
		HashMap<String,Long> map=new HashMap<>();
		
		int jou=1 << n;
		for(int i=0;i<jou;i++){
			String tane="";
			String taneb="";
			for(int j=0;j<n;j++){
				if(((i >> j) & 1)==1){
					tane+=a[j];
				}else{
					taneb+=a[j];
				}
			}
			String key=tane+":"+taneb;
			if(map.containsKey(key)){
				map.put(key,map.get(key)+1);
			}else map.put(key,1L);
		}
		return map;
	}
}