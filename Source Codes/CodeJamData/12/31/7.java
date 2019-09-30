import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class Main1 {
	/**
	 * @param args
	 * @throws IOException 
	 */
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(in.readLine());
		int cnt = 0;
		while(t>0){
			t--;cnt++;
			int n = Integer.parseInt(in.readLine());
			List<MyObject> l = new ArrayList<MyObject>();
			for(int i=0; i<n; i++){
				String s = in.readLine();
				String [] ss = s.split(" ");
				int x = Integer.parseInt(ss[0]);
				MyObject myObject = new MyObject(i+1);
				for(int j=0; j<x; j++){
					myObject.addConnected(Integer.parseInt(ss[j+1]));
				}
				l.add(myObject);
			}
			boolean diamond = false;
			for(MyObject m : l){
				if(diamond) break;
				List<Integer> ll = m.getMethods(l);
				int prev = -1;
				for(Integer i : ll){
					if(i==prev){
						diamond = true;
					}else{
						prev = i;
					}
					
				}
			}
			if(diamond){
				out.write("Case #"+cnt+": Yes\n");
				//System.out.println("Case #"+cnt+": Yes");
			}else{
				out.write("Case #"+cnt+": No\n");
				//System.out.println("Case #"+cnt+": No");
			}
			
			
		}

		in.close();
		out.close();

	}
}

class MyObject{
	
	int num;
	int done = 0;
	List<Integer> methods = new ArrayList<Integer>();
	List<Integer> connected = new ArrayList<Integer>();
	
	public MyObject(int num) {
		this.num = num;
		methods.add(num);
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public List<Integer> getMethods(List<MyObject> list) {
		if(this.done == 0){
			for(Integer i: this.connected){
				methods.addAll(list.get(i-1).getMethods(list));
				if(methods.size() > 1100){
					break;
				}
			}
			this.done = 1;
			Collections.sort(methods);
		}
		return methods;
	}
	public void setMethods(List<Integer> methods) {
		this.methods = methods;
	}
	public List<Integer> getConnected() {
		return connected;
	}
	public void setConnected(List<Integer> connected) {
		this.connected = connected;
	}
	
	public void addConnected(int x){
		this.connected.add(x);
	}
	
	public void addMethod(int x){
		this.methods.add(x);
	}
	public int getDone() {
		return done;
	}
	public void setDone(int done) {
		this.done = done;
	}
	
	
}
