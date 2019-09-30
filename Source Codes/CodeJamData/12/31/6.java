import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Diamond {
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
			List<ClassesGiven> l = new ArrayList<ClassesGiven>();
			for(int i=0; i<n; i++){
				String s = in.readLine();
				String [] ss = s.split(" ");
				int x = Integer.parseInt(ss[0]);
				ClassesGiven objectOfClass = new ClassesGiven(i+1);
				for(int j=0; j<x; j++){
					objectOfClass.addConnected(Integer.parseInt(ss[j+1]));
				}
				l.add(objectOfClass);
			}
			boolean hasDiamon = false;
			for(ClassesGiven m : l){
				if(hasDiamon) break;
				List<Integer> ll = m.getMethods(l);
				int prev = -1;
				for(Integer i : ll){
					if(i==prev){
						hasDiamon = true;
					}else{
						prev = i;
					}
					
				}
			}
			if(hasDiamon){
				out.write("Case #"+cnt+": Yes\n");
			}else{
				out.write("Case #"+cnt+": No\n");
			}
			
			
		}

		in.close();
		out.close();

	}
}

class ClassesGiven{
	
	int num;
	int done = 0;
	List<Integer> methods = new ArrayList<Integer>();
	List<Integer> connected = new ArrayList<Integer>();
	
	public ClassesGiven(int num) {
		this.num = num;
		methods.add(num);
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public List<Integer> getMethods(List<ClassesGiven> list) {
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
