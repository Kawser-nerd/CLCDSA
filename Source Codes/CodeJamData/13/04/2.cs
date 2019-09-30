using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Solver {
	class Solver {
		Boolean isInFile, isOutFile;
		StreamReader reader;
		StreamWriter writer;

		public Solver(string[] args) {
			isInFile = (args.Length > 0);
			if (isInFile)
				reader = new StreamReader(args[0]);
			isOutFile = (args.Length > 1);
			if (isOutFile)
				writer = new StreamWriter(args[1]);
		}

		public void Write(string str) {
			if (isOutFile)
				writer.Write(str);
			Console.Write(str);
		}

		public void Writeln(string str) {
			if (isOutFile)
				writer.WriteLine(str);
			Console.WriteLine(str);
		}

		public string Readln() {
			return reader.ReadLine().Trim();
		}

		static void Main(string[] args) {
			new Solver(args).Solve();
		}
		
		public void printCKey(int[][] cKey){
			for(int i=1; i<cKey.Length; i++){
				foreach(int k in cKey[i])
					Write(k + " ");
				Writeln("");
			}
		}
		
		public void printKey(int[] key){
			for(int i=1; i<key.Length; i++){
				if(key[i] != 0)
					Writeln("key" + i + " = " + key[i]);
			}
		}
		
		public void printAnswer(int[] answer, int step){
			for(int i=0; i<step; i++)
				Write(answer[i] + " ");
			Writeln("");
		}

		public void Solve() {
			int T = int.Parse(Readln());
			for (int i = 1; i <= T; i++) {
				Write("Case #" + i + ": ");
				SolveOne();
				Writeln("");
			}
			writer.Close();
			reader.Close();
		}
		
		public Boolean TryStep(int step, int[] answer, int N, int[] key, int keyRemain, Boolean[] cOpened, int[] c, int[][] cKey){
			if(step == N-1)
				return true;
			if(step >= N)
				return false;
			if(keyRemain <= 0)
				return false;
			
			//rough checking
			int[] keyClone = new int[201];
			for(int i=1; i<=200; i++)
				keyClone[i] = key[i];
			Boolean[] cOpenedClone = new Boolean[N+1];
			for(int i=1; i<=N; i++)
				cOpenedClone[i] = cOpened[i];
			
			Boolean keyHasUpdate;
			do{
				keyHasUpdate = false;
				for(int i=1; i<=N; i++){
					if(!cOpenedClone[i] && keyClone[c[i]] > 0){
						cOpenedClone[i] = true;
						foreach(int k in cKey[i]){
							if(keyClone[k] == 0)
								keyHasUpdate = true;
							keyClone[k]++;
						}
					}
				}
			}while(keyHasUpdate);
			
			for(int i=1; i<=N; i++){
				if(!cOpened[i] && keyClone[c[i]] <= 0)
					return false;
			}
			
			
			//printAnswer(answer, step);
			for(int i=1; i<=N ; i++){
				if(!cOpened[i] && key[c[i]] > 0){
					//open
					cOpened[i] = true;
					key[c[i]]--;
					keyRemain--;
					foreach(int k in cKey[i]){
						key[k]++;
						keyRemain++;
					}
					answer[step+1] = i;
					
					//try
					Boolean result = TryStep(step+1, answer, N, key, keyRemain, cOpened, c, cKey);
					if(result)
						return true;
					
					//close (reset)
					cOpened[i] = false;
					key[c[i]]++;
					keyRemain++;
					foreach(int k in cKey[i]){
						key[k]--;
						keyRemain--;
					}
					
				}
			}
			
			
			return false;
		}

		public void SolveOne() {
			/* read data */
			string[] temp = Readln().Split(' ');
			int K = int.Parse(temp[0]);
			int N = int.Parse(temp[1]);
			int[] key = new int[201];
			for(int i=1 ; i<=200 ; i++){
				key[i] = 0;
			}
			int keyRemain = 0;
			temp = Readln().Split(' ');
			for (int i = 0; i < K; i++){
				key[int.Parse(temp[i])]++;
				keyRemain++;
			}
			int[] c = new int[N+1];
			Boolean[] cOpened = new Boolean[N+1];
			int[][] cKey = new int[N+1][];
			for(int i=1; i<=N; i++){
				temp = Readln().Split(' ');
				c[i] = int.Parse(temp[0]);
				cOpened[i] = false;
				cKey[i] = new int[int.Parse(temp[1])];
				for(int j=0; j<int.Parse(temp[1]); j++){
					cKey[i][j] = int.Parse(temp[j+2]);
				}
			}

			/* solve */
			//check key need
			int[] keyNeed = new int[201];
			int[] keyTotal = new int[201];
			for(int i=1; i<=200; i++){
				keyNeed[i] = 0;
				keyTotal[i] = key[i];
			}
			for(int i=1; i<=N; i++){
				keyNeed[c[i]]++;
				foreach(int j in cKey[i])
					keyTotal[j]++;
			}
			for(int i=1; i<=200; i++){
				if(keyNeed[i] > keyTotal[i]){
					Write("IMPOSSIBLE");
					return;
				}
			}
			
			//
			int[] answer = new int[N];
			Boolean result = TryStep(-1, answer, N, key, keyRemain, cOpened, c, cKey);
			if(result)
				for(int i=0 ; i<N ; i++)
					Write(answer[i] + " ");
			else
				Write("IMPOSSIBLE");
		}
	}
}