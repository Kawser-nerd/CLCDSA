using System;
using System.Collections.Generic;
class Program{
	static List<long> he1=new List<long>();
	static List<long> he2=new List<long>();
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		long[] s=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		long[] a1=new long[n*3];
		long[] a2=new long[n*3];
		for(int i=n*3-1;i>=n*2;i--){
			a2[n*2]+=s[i];
			heapa2(s[i]);
		}
		for(int i=n*2-1;i>=n;i--){
			heapa2(s[i]);
			a2[i]=a2[i+1]+s[i]-he2[0];
			heapr2();
		}
		for(int i=0;i<n;i++){
			a1[n-1]+=s[i];
			heapa1(s[i]);
		}
		long ans=a1[n-1]-a2[n];
		for(int i=n;i<n*2;i++){
			heapa1(s[i]);
			a1[i]=a1[i-1]+s[i]-he1[0];
			heapr1();
			ans=Math.Max(ans,a1[i]-a2[i+1]);
		}
		Console.WriteLine(ans);
	}
	static void heapa1(long a){
		he1.Add(a);
		int j=he1.Count-1;
		while(he1[j]<he1[(j-1)/2]){
			long v=he1[j];
			he1[j]=he1[(j-1)/2];
			he1[(j-1)/2]=v;
			j=(j-1)/2;
		}
	}
	static void heapr1(){
		he1[0]=he1[he1.Count-1];
		he1.RemoveAt(he1.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he1.Count){
				if(he1[j*2+1]<he1[j*2+2]){j=j*2+1;}
				else{j=j*2+2;}
			}
			else if(j*2+1<he1.Count){j=j*2+1;}
			else{break;}
			if(he1[j]>=he1[(j-1)/2]){break;}
			long v=he1[j];
			he1[j]=he1[(j-1)/2];
			he1[(j-1)/2]=v;
		}
	}
	static void heapa2(long a){
		he2.Add(a);
		int j=he2.Count-1;
		while(he2[j]>he2[(j-1)/2]){
			long v=he2[j];
			he2[j]=he2[(j-1)/2];
			he2[(j-1)/2]=v;
			j=(j-1)/2;
		}
	}
	static void heapr2(){
		he2[0]=he2[he2.Count-1];
		he2.RemoveAt(he2.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he2.Count){
				if(he2[j*2+1]>he2[j*2+2]){j=j*2+1;}
				else{j=j*2+2;}
			}
			else if(j*2+1<he2.Count){j=j*2+1;}
			else{break;}
			if(he2[j]<=he2[(j-1)/2]){break;}
			long v=he2[j];
			he2[j]=he2[(j-1)/2];
			he2[(j-1)/2]=v;
		}
	}
}