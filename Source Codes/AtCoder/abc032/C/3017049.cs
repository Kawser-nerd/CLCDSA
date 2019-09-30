using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] arr=new int[s[0]];
		long w=1;
		int a=0,n=0;

		if(s[1]!=0){
			for(int i=0;i<s[0];i++){
				arr[i]=int.Parse(Console.ReadLine());
				if(arr[i]==0){a=s[0];break;}
				w*=arr[i];
				n++;
				if(w<=s[1]){a=Math.Max(a,n);}
				else{
					while(w>s[1]){
						n--;
						w/=arr[i-n];
					}
				}
			}
		}
		else{
			for(int i=0;i<s[0];i++){
				arr[i]=int.Parse(Console.ReadLine());
				if(arr[i]==0){a=s[0];break;}
			}
		}
		Console.WriteLine("{0}",a);
	}
}